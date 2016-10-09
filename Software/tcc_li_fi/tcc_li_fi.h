#ifndef tcc_li_fi_h
#define tcc_li_fi_h

// Comm messages have a fixed size
#define MESSAGE_SIZE 33

// Board's role defined by hardware
#define ROLE_PIN 24
#define SENDER HIGH
#define RECEIVER LOW

// From pin_comm.ino
void setupPinComm();
void receivePhrase(unsigned char * message, unsigned char messageSize);
void sendPhrase(unsigned char * message, unsigned char messageSize);

// From btn_display.ino
void displayTextMessage(unsigned char * message, unsigned char messageSize);
void translateDisplayMessage(unsigned char * message, unsigned char messageSize);
void enableDisplayControl();
void setupDisplay(boolean showDefaultMessage);


// Sender or receiver
static char boardRole;

// Comm message
static unsigned char message[MESSAGE_SIZE];

#endif
