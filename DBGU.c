#include "AT91SAM9263.h"
#include "DBGU.h"

int initialize( int bits_no,  int stop_bits,  int has_parity_bit) {
	if(bits_no != 8 || stop_bits != 1 || has_parity_bit != 0) {
	  return -1;
	}
	disableInterrupts();
	resetTransmitter();
	turnTransmitterOff();
	resetReceiver();
	turnReceiverOff();
	configureBaudRate();
	configure8N1();
	configurePIO();
	turnReceiverOn();
	turnTransmitterOn();
	return 0;
}

void disableInterrupts() {
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_RXRDY;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_TXRDY;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_ENDRX;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_ENDTX;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_OVRE;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_FRAME;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_PARE;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_TXEMPTY;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_TXBUFE;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_RXBUFF;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_COMM_TX;
	AT91C_BASE_DBGU->DBGU_IDR=AT91C_US_COMM_RX;
}

void resetTransmitter() {
	AT91C_BASE_DBGU->DBGU_CR=AT91C_US_RSTTX;
}

void resetReceiver() {
	AT91C_BASE_DBGU->DBGU_CR=AT91C_US_RSTRX;
}

void turnReceiverOff() {
  AT91C_BASE_DBGU->DBGU_CR = AT91C_US_RXDIS;
}

void turnTransmitterOff() {
 AT91C_BASE_DBGU->DBGU_CR = AT91C_US_TXDIS; 
}

void turnTransmitterOn() {
	AT91C_BASE_DBGU->DBGU_CR = AT91C_US_TXEN;
}

int checkIfReceiverReady() {
  return (AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_RXRDY); 
}

int checkIfTransmitterReady() {
  return (!(AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_TXRDY));
}

void turnReceiverOn() {
	AT91C_BASE_DBGU->DBGU_CR = AT91C_US_RXEN; 
}

void configureBaudRate() {
	AT91C_BASE_DBGU->DBGU_BRGR = CD;
}

void configure8N1() {
	AT91C_BASE_DBGU->DBGU_MR = AT91C_US_CHMODE_NORMAL;
	AT91C_BASE_DBGU->DBGU_MR = AT91C_US_PAR_NONE;
}

void printAlphabet() {
 int letter = 'A';
 while( letter <= 'Z' ) {
   sendCharacter((char)letter);
   letter++;
 }
 
 letter = 'A';
 while( letter <= 'Z' ) {
   sendCharacter((char)letter + CHARACTERS_OFFSET);
   letter++;
 }
}

void printBuffer(char *string) {
 
  while(*string != '\0') {
    sendCharacter(*string);
    string++;
  }
}

char readCharacter() {
 while(!checkIfReceiverReady()){}
 return AT91C_BASE_DBGU->DBGU_RHR;
}

void reverseString() {
 char letter = readCharacter();
 if(letter >= 'a' && letter <= 'z') {
  letter -= CHARACTERS_OFFSET;
 } else if(letter >= 'A' && letter <= 'Z') {
  letter += CHARACTERS_OFFSET; 
 }
 sendCharacter(letter);
}

void sendCharacter(char letter) {
  while(!(AT91C_BASE_DBGU->DBGU_CSR & AT91C_US_TXRDY)) {}
    AT91C_BASE_DBGU->DBGU_THR = (unsigned int)letter;
}

void configurePIO() {
  AT91C_BASE_PIOC->PIO_PDR = AT91C_PC30_DRXD;
  AT91C_BASE_PIOC->PIO_PDR = AT91C_PC31_DTXD;
  
  AT91C_BASE_PIOC->PIO_ASR = AT91C_PC30_DRXD;
  AT91C_BASE_PIOC->PIO_ASR = AT91C_PC31_DTXD;
}

