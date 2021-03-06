#include "AT91SAM9263.h"
#include "DBGU.h"

void initialize() {
	disableInterrupts();
	resetTransmitter();
	resetReceiver();
	configureBaudRate();
	configure8N1();
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

void turnTransmitterOn() {
	AT91C_BASE_DBGU->DBGU_CR = AT91C_US_TXEN;
}

void turnReceiverOn() {
	AT91C_BASE_DBGU->DBGU_CR = AT91C_US_RXEN; 
}

void configureBaudRate() {
	AT91C_BASE_DBGU->DBGU_BRGR = (int)(MASTERCLOCK/(16*BAUDRATE));
}

void configure8N1() {
	AT91C_BASE_DBGU->DBGU_MR = AT91C_US_CHMODE_NORMAL;
	AT91C_BASE_DBGU->DBGU_MR = AT91C_US_PAR_NONE;
}

void sendCharacter(char letter) {
  AT91C_BASE_DBGU->DBGU_THR = (unsigned int)letter;
}