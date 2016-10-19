#ifndef encoding_8b10b_h
#define encoding_8b10b_h

// rd must be always initilized as negative
#define INITIAL_RD_VALUE -1

// Running Disparity
static signed char rd = INITIAL_RD_VALUE;

// Encoding functions
void setEncodingRD(char rdValue);
void setup8B10B();
uint16_t encode8B10B(unsigned char data);
unsigned char decode8B10B(uint16_t data);
uint16_t encode10bControl(uint16_t controlNumber);
uint16_t decode10bControl(uint16_t encodedControl);

#endif
