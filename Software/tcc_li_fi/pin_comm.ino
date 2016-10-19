#include "pin_comm.h"

void TC3_Handler() {
    TC_GetStatus(TC1, 0); // TC1, ch 0
    if (sendBitReady) {
        digitalWrite(OUTPUT_PIN, commPinState);
        sendBitReady = false;
    } else if (receiveBitReady) {
        commPinState = digitalRead(INPUT_PIN);
        receiveBitReady = false;
    }
}

static inline void sendBit(unsigned char bit) {
    commPinState = (bit != 0u);
    sendBitReady = true;
    while (sendBitReady) {
        ;
    }
}

static void send10b(uint16_t data, unsigned char bits) {

    uint16_t converter = 1u;

    // loop initializes converter as (0010 0000 0000)2 when bits = 10
    for (converter <<= (bits - 1); converter; converter >>= 1) {
        sendBit(data & converter);
    }
}

static void sendLetter(unsigned char letter) {

    uint16_t encodedLetter;

    encodedLetter = encode8B10B(letter);
    encodedLetter |= validDataHeader;
    send10b(encodedLetter, DATA_BIT_SIZE + VALIDATION_HEADER_BIT_SIZE);
}

static uint32_t generateSetBitData(unsigned char bitQtt) {

    // For bitQtt = 30, should return the 30-bit integer 1073741823 = 0x3FFFFFFF = 0011 1111 1111 1111 1111 1111 1111 1111
    uint32_t data = 0u;

    for (; bitQtt > 3; bitQtt -= 4) {
        data = (data << 4) | 0xFu;
    }

    for (; bitQtt; bitQtt--) {
        data = (data << 1) | 1u;
    }

    return data;
}

static void sendSyncMessage() {

    unsigned char len;
    uint16_t data;
    uint32_t converter;

    len = sizeof(syncChars) / sizeof(syncChars[0]);
    converter = generateSetBitData(DATA_BIT_SIZE);
    converter <<= ((len - 1) * DATA_BIT_SIZE);

    for (; len; len--) {
        data = (syncMessage  & converter) >> ((len - 1) * DATA_BIT_SIZE);
        converter >>= DATA_BIT_SIZE;
        send10b(data, DATA_BIT_SIZE);
    }
}

void sendPhrase(unsigned char * message, unsigned char messageSize) {

    unsigned long i;

    sendSyncMessage();

    i = micros();
    while (micros() < i + 1000) {
        ;
    }

    for (i = 0; i < messageSize && message[i] != '\0'; i++) {
        sendLetter(message[i]);
    }

    sendLetter('\0');
}

static inline unsigned char receiveBit() {
    receiveBitReady = true;
    while (receiveBitReady) {
        ;
    }
    return (commPinState ? 1u : 0u);
}

static uint16_t receive10b() {

    unsigned char i;
    uint16_t data = 0u, header = 0u;

    while (header != validDataHeader) {
        data = (data << 1) | receiveBit();
        header = data & dataHeaderIsolator;
    }

    return data & dataHeaderRemover;
}

static unsigned char receiveLetter() {

    uint16_t encodedLetter;

    encodedLetter = receive10b();
    return decode8B10B(encodedLetter);
}

static void waitSyncMessage() {

    uint32_t converter, data = 0u;

    converter = generateSetBitData(SYNC_MESSAGE_BIT_SIZE);

    while (data != syncMessage) {
        data = ((data << 1) | receiveBit()) & converter;
    }
}

void receivePhrase(unsigned char * message, unsigned char messageSize) {

    unsigned char i = 0;

    waitSyncMessage();

    do {
        message[i] = receiveLetter();
    } while (++i < messageSize);

    message[i - 1] = '\0';
}

static void startTimer(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t frequency) {

    // Parameters: Pointer to Timer Clock, TC's channel, the IRQ for that channel and the desired frequency in Hz

    uint32_t rc = VARIANT_MCK / (128 * frequency); // 128 because we select TIMER_CLOCK4 below

    pmc_set_writeprotect(false);
    pmc_enable_periph_clk((uint32_t) irq);

    TC_Configure(tc, channel, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK4);
    TC_SetRA(tc, channel, rc / 2); // 50% high, 50% low
    TC_SetRC(tc, channel, rc);
    TC_Start(tc, channel);

    tc->TC_CHANNEL[channel].TC_IER =  TC_IER_CPCS;
    tc->TC_CHANNEL[channel].TC_IDR = ~TC_IER_CPCS;

    NVIC_EnableIRQ(irq);
}

static void generateSyncMessage() {

    unsigned char i, len;

    len = sizeof(syncChars) / sizeof(syncChars[0]);
    syncMessage = 0u;

    for (i = 0u; i < len; i++) {
        syncMessage = (syncMessage << DATA_BIT_SIZE) | encode8B10B(syncChars[i]);
    }
}

void setupPinComm() {
    pinMode(OUTPUT_PIN, OUTPUT);
    pinMode(INPUT_PIN, INPUT);
    setup8B10B();
    generateSyncMessage();
    startTimer(TC1, 0, TC3_IRQn, COMM_BIT_RATE); // TC1, channel 0, the IRQ for that channel and the desired frequency (in Hz)
}
