#ifndef encoding_8b10b_h
#define encoding_8b10b_h

// rd must be always initilized as negative
#define INITIAL_RD_VALUE -1

// Running Disparity
static char rd = INITIAL_RD_VALUE;

// Encoding functions
void setEncodingRD(char rdValue);
void setup8B10B();
unsigned int encode8B10B(unsigned char data);
unsigned char decode8B10B(unsigned int data);
unsigned int encode10bControl(unsigned int controlNumber);
unsigned int decode10bControl(unsigned int encodedControl);

#endif
