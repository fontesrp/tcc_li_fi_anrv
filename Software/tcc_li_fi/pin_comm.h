#ifndef pin_comm_h
#define pin_comm_h

#if defined(__AVR_ATmega2560__) // Arduino Mega 2560
#define OUTPUT_PIN 22
#define INPUT_PIN  23
#elif defined(__AVR_ATmega328P__) // Arduino UNO R3
#define OUTPUT_PIN 2
#define INPUT_PIN  4
#endif

// Bit sizes are used as 'unsigned char'
#define DATA_BIT_SIZE 10u
#define SYNC_MESSAGE_BIT_SIZE 30u

// Factor used to adjust the delay time to the imprecision of the Arduino functions delayMicroseconds() and delay()
#define DELAY_CORRECTION_FACTOR 5u
// The best factors for different bit rates are:
// 12u -> 1 kbps (T = 1000 us)
//  5u -> 2 kbps (T =  500 us)
//  2u -> 4 kbps (T =  250 us)
//  1u -> 8 kbps (T =  125 us)

// -- encoding_8b10b.ino
void setup8B10B();
unsigned int encode8B10B(unsigned char data);
unsigned char decode8B10B(unsigned int data);
// --

// All bit times are in microseconds
const unsigned long desiredBitTime = 500u; // Rate = 2 kbps
unsigned long minimumBitTime = 0u;

// Delays for achieving the desired bit time
unsigned int microBitDelay = 0u;
unsigned int milliBitDelay = 0u;

// Extended ASCII codes for omega, dash and start of text
const unsigned char syncChars[3] = {234u, 45u, 2u}; // 0xEA, 0x2D, 0x02 = Ohm, '-', STX (Coded message is: 0x15E, 0x2C9, 0x12B)
unsigned long syncMessage; // 0x15EB252B = 0001 0101 1110 1011 0010 0101 0010 1011

#endif
