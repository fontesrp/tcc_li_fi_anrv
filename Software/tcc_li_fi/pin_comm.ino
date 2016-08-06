#include "pin_comm.h"

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

	unsigned char i;
	unsigned int converter = 1u;
	char pinState;

	// noInterrupts();

	for (i = 0u; i < DATA_BIT_SIZE; i++) {
		pinState  = ((data & converter) == 0u ? LOW : HIGH);
		converter = converter << 1;
		digitalWrite(OUTPUT_PIN, pinState);
		delayMicroseconds(microBitDelay);
		delay(milliBitDelay);
	}

	// interrupts();
}

void sendLetter(unsigned char letter) {

	unsigned int encodedLetter;

	encodedLetter = encode8B10B(letter);
	send10b(encodedLetter);
}

void sendSyncMessage() {

	unsigned char i, len;
	unsigned int converter, data;

	converter = generateSetBitData(DATA_BIT_SIZE);
	len = sizeof(syncChars) / sizeof(syncChars[0]);

	for (i = 0u; i < len; i++) {
		data = (syncMessage >> (i * DATA_BIT_SIZE)) & converter;
		send10b(data);
	}
}

void sendPhrase(unsigned char * message, unsigned char messageSize) {

	unsigned char i;

	sendSyncMessage();

	for (i = 0; i < messageSize && message[i] != '\0'; i++) {
		sendLetter(message[i]);
	}

	sendLetter('\0');
}

unsigned int receive10b() {

	unsigned char i;
	unsigned int data = 0u;
	char pinState;

	// noInterrupts();

	for (i = 0u; i < DATA_BIT_SIZE; i++) {
		pinState = digitalRead(INPUT_PIN);
		data = (data << 1) | (pinState == LOW ? 0u : 1u);
		delayMicroseconds(microBitDelay);
		delay(milliBitDelay);
	}

	// interrupts();

	return data;
}

unsigned char receiveLetter() {

	unsigned int encodedLetter;

	encodedLetter = receive10b();
	return decode8B10B(encodedLetter);
}

void waitSyncMessage() {

	unsigned char i, bitsReceived = 0u;
	unsigned long converter, data = 0u;
	char pinState;

	// noInterrupts();
	converter = generateSetBitData(SYNC_MESSAGE_BIT_SIZE);

	while (data != syncMessage) {

		pinState = digitalRead(INPUT_PIN);
		data = (data << 1) | (pinState == LOW ? 0u : 1u);

		if (bitsReceived < SYNC_MESSAGE_BIT_SIZE) {
			bitsReceived++;
		} else {
			data &= converter;
		}

		delayMicroseconds(microBitDelay);
		delay(milliBitDelay);
	}

	// interrupts();
}

void receivePhrase(unsigned char * message, unsigned char messageSize) {

	unsigned char i;

	waitSyncMessage();

	for (i = 0; i < messageSize; i++) {
		message[i] = receiveLetter();
		if (message[i] == '\0') {
			i = messageSize;
		}
	}

	if (i == messageSize) {
		message[i - 1] = '\0';
	}
}

void generateSyncMessage() {

	unsigned char i, len;

	len = sizeof(syncChars) / sizeof(syncChars[0]);
	syncMessage = 0u;

	for (i = 0u; i < len; i++) {
		syncMessage = syncMessage << DATA_BIT_SIZE;
		syncMessage |= encode8B10B(syncChars[i]);
	}
}

unsigned int generateAlternatingBitData(unsigned char bitQtt) {

	// For bitQtt = 10, should return the 10-bit integer 682 = 0x2AA = 0010 1010 1010

	unsigned int data = 0u;

	for (; bitQtt; bitQtt--) {
		data = (data << 1) | ((bitQtt + 1u) % 2u); // Set all odd bits to 1
	}

	return data;
}

unsigned long getMinBitTime() {

	// On both Arduino UNO R3 and Arduino Mega 2560, the maximum bit rate is about 277,777 bps (time ~= 36 us, for 10 bits)

	unsigned long time;
	unsigned int data;

	data = generateAlternatingBitData(DATA_BIT_SIZE);

	time = micros();
	send10b(data);
	time = micros() - time;

	return time / DATA_BIT_SIZE;
}

void setBitDelay() {

	microBitDelay = 0u;
	milliBitDelay = 0u;

	if (!minimumBitTime) {
		minimumBitTime = getMinBitTime();
	}

	microBitDelay = desiredBitTime - minimumBitTime - DELAY_CORRECTION_FACTOR; // Everything in microseconds

	// Arduino's documentation warns that, for values greater than 16,383, the function delayMicroseconds() won't produce an accurate delay
	// For safety, a cap is put at 10,000. For delays greater than that, the delay() function is used
	if (microBitDelay >= 10000u) {
		microBitDelay = 0u;
		milliBitDelay = (desiredBitTime - minimumBitTime) / 1000u; // Converts to milliseconds
	}
}

void setupPinComm() {
	pinMode(OUTPUT_PIN, OUTPUT);
	pinMode(INPUT_PIN, INPUT);
	setup8B10B();
	setBitDelay();
	generateSyncMessage();
}
