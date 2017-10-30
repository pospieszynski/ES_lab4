#include "AT91SAM9263.h"
#define MASTERCLOCK 100000000
#define BAUDRATE 115200
#define CD 54
#define CHARACTERS_OFFSET 32

int initialize( int bits_no,  int stop_bits,  int has_parity_bit);
//void printAlphabet();
void configurePIO();
void disableInterrupts();
void resetTransmitter();
void resetReceiver();
void turnTransmitterOn();
void turnReceiverOn();
void configureBaudRate();
void configure8N1();
void configurePIO();
void sendCharacter(char);