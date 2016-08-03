#ifndef tcc_li_fi_h
#define tcc_li_fi_h

// encoding_8b10b.ino
void setup8B10B();
unsigned int encode8B10B(unsigned char data);
unsigned char decode8B10B(unsigned int data);

// pin_comm.ino
void setupPinComm();
unsigned int receive10b();
void send10b(unsigned int data);

#endif
