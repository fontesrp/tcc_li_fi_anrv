#ifndef tcc_li_fi_h
#define tcc_li_fi_h

// -- encoding_8b10b.ino
void setup8B10B();
unsigned int encode8B10B(unsigned char data);
unsigned char decode8B10B(unsigned int data);
// --

// -- pin_comm.ino

// Pointer to the 8b10b encoding function
#ifndef ENCODE_FUNCTION
#define ENCODE_FUNCTION
typedef unsigned int (*encodeFunction)(unsigned char data);
#endif

// Functions
void setupPinComm();
void generateSyncMessage(encodeFunction encode);
void sendSyncMessage();
void waitSyncMessage();
unsigned int receive10b();
void send10b(unsigned int data);

// --

#define MESSAGE_SIZE 21

#if defined(__AVR_ATmega2560__) // Arduino Mega 2560 (sender)
const unsigned char message[MESSAGE_SIZE] = "Testing Arduino comm";
#elif defined(__AVR_ATmega328P__) // Arduino UNO R3 (receiver)
volatile unsigned char message[MESSAGE_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
#endif

#endif
