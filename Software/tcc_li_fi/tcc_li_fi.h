#ifndef tcc_li_fi_h
#define tcc_li_fi_h

// Comm messages have a fixed size
#define MESSAGE_SIZE 21

// Board's role defined by hardware
#define ROLE_PIN 24
#define SENDER HIGH
#define RECEIVER LOW

// From pin_comm.ino
void setupPinComm();
void receivePhrase(unsigned char * message, unsigned char messageSize);
void sendPhrase(unsigned char * message, unsigned char messageSize);

// Sender or receiver
char boardRole;

// Comm messages
unsigned char sendMessage[MESSAGE_SIZE] = "Testing Arduino comm";
unsigned char receivedMessage[MESSAGE_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

#endif
