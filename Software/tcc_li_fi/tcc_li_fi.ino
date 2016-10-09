#include "tcc_li_fi.h"

void initMessage() {
	int i;
	for (i = 0; i < MESSAGE_SIZE; i++) {
		message[i] = '\0';
	}
}

void setup() {
	Serial.begin(9600);
	pinMode(ROLE_PIN, INPUT);
	boardRole = digitalRead(ROLE_PIN);
	initMessage();
	setupPinComm();
	setupDisplay(boardRole);
}

void loop() {

	// int i, check = 0;

	Serial.println("loop: fired");

	if (boardRole == SENDER) {
		Serial.println("loop: boardRole = SENDER");
		enableDisplayControl();
		translateDisplayMessage(message, MESSAGE_SIZE);
		sendPhrase(message, MESSAGE_SIZE);
		Serial.println("loop: message sent");
	} else if (boardRole == RECEIVER) {
		Serial.println("loop: boardRole = RECEIVER");
		receivePhrase(message, MESSAGE_SIZE);
		displayTextMessage(message, MESSAGE_SIZE);
		Serial.println("loop: message received");
	} else {
		Serial.println("[error] loop: invalid boardRole");
	}

	/*Serial.print("loop: message =");

	for (i = 0; i < MESSAGE_SIZE; i++) {
		Serial.print(" 0x");
		Serial.print(message[i], HEX);
		if (message[i] != '\0' && message[i] == outputMessage[i]) {
			check++;
		}
	}

	Serial.println("");

	if (boardRole == RECEIVER) {
		// delay(10000);
		Serial.print(check, DEC);
		Serial.print(" correct letters");
		Serial.println("");
	}*/
}
