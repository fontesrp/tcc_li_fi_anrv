#ifndef tcc_li_fi_h
#define tcc_li_fi_h

// -- pin_comm.ino
void setupPinComm();
void receivePhrase(unsigned char * message, unsigned char messageSize);
void sendPhrase(unsigned char * message, unsigned char messageSize);
// --

#define MESSAGE_SIZE 21
#define ROLE_PIN 24
#define SENDER HIGH
#define RECEIVER LOW

char boardRole;

unsigned char sendMessage[MESSAGE_SIZE] = "Testing Arduino comm";
unsigned char receivedMessage[MESSAGE_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

#endif
