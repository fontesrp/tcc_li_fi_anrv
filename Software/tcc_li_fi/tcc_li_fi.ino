#include "tcc_li_fi.h"

void setup() {
	setupPinComm();
}

#if defined(__AVR_ATmega2560__) // Arduino Mega 2560 sending

void loop() {

	sendPhrase(message, MESSAGE_SIZE);
}

#elif defined(__AVR_ATmega328P__) // Arduino UNO R3 receiving

void loop() {

	receivePhrase(message, MESSAGE_SIZE);
}

#endif
