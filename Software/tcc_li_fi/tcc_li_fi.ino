#include "tcc_li_fi.h"

void setup() {
	setup8B10B();
	setupPinComm();
	generateSyncMessage(encode8B10B);
}

#if defined(__AVR_ATmega2560__) // Arduino Mega 2560 sending

void loop() {

	int i;
	unsigned int encodedLetter;

	sendSyncMessage();

	for (i = 0; i < MESSAGE_SIZE; i++) {
		encodedLetter = encode8B10B(message[i]);
		send10b(encodedLetter);
	}
}

#elif defined(__AVR_ATmega328P__) // Arduino UNO R3 receiving

void loop() {

	int i;
	unsigned int encodedLetter;

	waitSyncMessage();

	for (i = 0; i < MESSAGE_SIZE; i++) {
		encodedLetter = receive10b();
		message[i] = decode8B10B(encodedLetter);
	}
}

#endif
