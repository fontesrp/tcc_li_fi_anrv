#include "tcc_li_fi.h"

void setup() {
	Serial.begin(9600);
	setupPinComm();
}

#if defined(__AVR_ATmega2560__) // Arduino Mega 2560 sending

void loop() {

	int i;

	Serial.println("main: fired");

	sendPhrase(message, MESSAGE_SIZE);

	Serial.println("main: message sent");
	Serial.print("main: message = ");

	for (i = 0; i < MESSAGE_SIZE; i++) {
		Serial.print(message[i]);
	}

	Serial.println("");

	// delay(10000);
}

#elif defined(__AVR_ATmega328P__) // Arduino UNO R3 receiving

void loop() {

	int i;

	Serial.println("main: fired");

	receivePhrase(message, MESSAGE_SIZE);

	Serial.println("main: message received");
	Serial.print("main: message = ");

	for (i = 0; i < MESSAGE_SIZE; i++) {
		Serial.print(message[i]);
	}

	Serial.println("");

	delay(10000);
}

#endif
