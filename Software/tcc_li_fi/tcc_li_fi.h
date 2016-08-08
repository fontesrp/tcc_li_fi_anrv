#ifndef tcc_li_fi_h
#define tcc_li_fi_h

// -- pin_comm.ino
void setupPinComm();
void receivePhrase(unsigned char * message, unsigned char messageSize);
void sendPhrase(unsigned char * message, unsigned char messageSize);
// --

#define MESSAGE_SIZE 21

#if defined(__AVR_ATmega2560__) // Arduino Mega 2560 (sender)
const char message[MESSAGE_SIZE] = "Testing Arduino comm\0";
#elif defined(__AVR_ATmega328P__) // Arduino UNO R3 (receiver)
char message[MESSAGE_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
#endif

#endif
