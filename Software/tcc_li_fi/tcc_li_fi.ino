#include "tcc_li_fi.h"

void setup() {
	Serial.begin(9600);
	pinMode(ROLE_PIN, INPUT);
	boardRole = digitalRead(ROLE_PIN);
	setupPinComm();
}

void loop() {

	unsigned char * message = sendMessage, check = 0;
	int i;

	Serial.println("main: fired");

	if (boardRole == SENDER) {
		sendPhrase(message, MESSAGE_SIZE);
		Serial.println("main: message sent");
	} else if (boardRole == RECEIVER) {
		message = receivedMessage;
		receivePhrase(message, MESSAGE_SIZE);
		Serial.println("main: message received");
	} else {
		Serial.println("[error] main: invalid boardRole");
	}

	Serial.print("main: message =");

	for (i = 0; i < MESSAGE_SIZE; i++) {
		Serial.print(" 0x");
		Serial.print(message[i], HEX);
		if (message[i] != '\0' && message[i] == sendMessage[i]) {
			check++;
		}
	}

	Serial.println("");

	if (boardRole == RECEIVER) {
		// delay(10000);
		Serial.print(check, DEC);
		Serial.print(" correct letters");
		Serial.println("");
	}
}
