#ifndef tcc_li_fi_h
#define tcc_li_fi_h

// Comm messages have a fixed size
#define MESSAGE_SIZE 33

// Board's role defined by hardware
#define ROLE_PIN 24
#define SENDER HIGH
#define RECEIVER LOW

// From pin_comm.ino
extern void setupPinComm();
extern void receivePhrase(unsigned char * message, unsigned char messageSize);
extern void sendPhrase(unsigned char * message, unsigned char messageSize);

// From btn_display.ino
extern void displayTextMessage(unsigned char * message, unsigned char messageSize);
extern void translateDisplayMessage(unsigned char * message, unsigned char messageSize);
extern void enableDisplayControl();
extern void setupDisplay(boolean showDefaultMessage);


// Sender or receiver
static char boardRole;

// Comm message
static unsigned char message[MESSAGE_SIZE];

#endif
