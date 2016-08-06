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

// All bit times are in microseconds
unsigned long minimumBitTime = 0u;
unsigned long desiredBitTime = 500u; // Rate = 2 kbps

// Delays for achieving the desired bit time
unsigned int microBitDelay = 0u;
unsigned int milliBitDelay = 0u;

// Extended ASCII codes for omega, dash and start of text
const unsigned char syncChars[3] = {234, 45, 2}; // 0xEA, 0x2D, 0x02 = Ohm, '-', STX (start of text)
unsigned long syncMessage;

// Pointer to the 8b10b encoding function; used to encode syncChars
#ifndef ENCODE_FUNCTION
#define ENCODE_FUNCTION
typedef unsigned int (*encodeFunction)(unsigned char data);
#endif

#endif
