#ifndef pin_comm_h
#define pin_comm_h

// Comm pins
#define OUTPUT_PIN 22
#define INPUT_PIN  23

// Bit sizes are used as 'unsigned char'
#define DATA_BIT_SIZE 10u
#define SYNC_MESSAGE_BIT_SIZE 30u

// Sets device to send/receive data at 1000 bits/sec ~= 1kHz
#define COMM_BIT_RATE 1000u;

// From encoding_8b10b.ino
void setup8B10B();
unsigned int encode8B10B(unsigned char data);
unsigned char decode8B10B(unsigned int data);

// Using interrupts
volatile boolean sendBitReady = false, receiveBitReady = false;
volatile int commPinState = LOW;

// Extended ASCII codes for omega, dash and start of text
const unsigned char syncChars[3] = {234u, 45u, 2u}; // 0xEA, 0x2D, 0x02 = Ohm, '-', STX (Coded message is: 0x15E, 0x2C9, 0x12B)
unsigned long syncMessage; // 0x15EB252B = 0001 0101 1110 1011 0010 0101 0010 1011

#endif
