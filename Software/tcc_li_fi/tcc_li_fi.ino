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
}
