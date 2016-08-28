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

unsigned long generateSetBitData(unsigned char bitQtt) {

	// For bitQtt = 30, should return the 30-bit integer 1073741823 = 0x3FFFFFFF = 0011 1111 1111 1111 1111 1111 1111 1111

	unsigned long data = 0u;

	for (; bitQtt > 3; bitQtt -= 4) {
		data = (data << 4) | 0xF;
	}

	for (; bitQtt; bitQtt--) {
		data = (data << 1) | 1u;
	}

	return data;
}

void send10b(unsigned int data) {

	unsigned int converter = 1u;

	// loop starts converter as (10 0000 0000)

	for (converter <<= (DATA_BIT_SIZE - 1); converter; converter >>= 1) {
		commPinState = ((data & converter) ? HIGH : LOW);
		sendBitReady = true;
		while (sendBitReady) {
			;
		}
	}
}

void sendLetter(unsigned char letter) {

	unsigned int encodedLetter;

	encodedLetter = encode8B10B(letter);
	send10b(encodedLetter);
}

void sendSyncMessage() {

	unsigned char len;
	unsigned int data;
	unsigned long converter;

	len = sizeof(syncChars) / sizeof(syncChars[0]);
	converter = generateSetBitData(DATA_BIT_SIZE);
	converter <<= ((len - 1) * DATA_BIT_SIZE);

	for (; len; len--) {
		data = (syncMessage  & converter) >> ((len - 1) * DATA_BIT_SIZE);
		converter >>= DATA_BIT_SIZE;
		send10b(data);
	}
}

void sendPhrase(unsigned char * message, unsigned char messageSize) {

	unsigned char i;

	Serial.println("pin_comm.ino sendPhrase: sending sync message");

	sendSyncMessage();

	Serial.println("pin_comm.ino sendPhrase: sync message sent");
	Serial.println("pin_comm.ino sendPhrase: sending phrase");

	for (i = 0; i < messageSize && message[i] != '\0'; i++) {
		sendLetter(message[i]);
	}

	sendLetter('\0');

	Serial.println("pin_comm.ino sendPhrase: phrase sent");
}

unsigned int receive10b() {

	unsigned char i;
	unsigned int data = 0u;

	for (i = 0u; i < DATA_BIT_SIZE; i++) {
		receiveBitReady = true;
		while (receiveBitReady) {
			;
		}
		data = (data << 1) | (commPinState == LOW ? 0u : 1u);
	}

	return data;
}

unsigned char receiveLetter() {

	unsigned int encodedLetter;

	encodedLetter = receive10b();
	return decode8B10B(encodedLetter);
}

void waitSyncMessage() {

	unsigned long converter, data = 0u;

	converter = generateSetBitData(SYNC_MESSAGE_BIT_SIZE);

	while (data != syncMessage) {
		receiveBitReady = true;
		while (receiveBitReady) {
			;
		}
		data = ((data << 1) | (commPinState == LOW ? 0u : 1u)) & converter;
	}
}

void receivePhrase(unsigned char * message, unsigned char messageSize) {

	unsigned char i;

	Serial.println("pin_comm.ino receivePhrase: waiting for sync message");

	waitSyncMessage();

	Serial.println("pin_comm.ino receivePhrase: sync message received");
	Serial.println("pin_comm.ino receivePhrase: getting phrase");

	for (i = 0; i < messageSize; i++) {
		message[i] = receiveLetter();
	}

	message[i - 1] = '\0';

	Serial.println("pin_comm.ino receivePhrase: returning phrase");
}

void startTimer(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t frequency) {

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

void generateSyncMessage() {

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
