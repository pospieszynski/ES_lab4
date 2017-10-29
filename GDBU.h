#include "AT91SAM9263.h"
#define MASTERCLOCK 100000000
#define BAUDRATE 115200
#define CHARACTERS_OFFSET 32

void initialize();
void disableInterrupts();
void resetTransmitter();
void resetReceiver();
void turnTransmitterOn();
void turnReceiverOn();
void configureBaudRate();
void configure8N1();
void sendCharacter();