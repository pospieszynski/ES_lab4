void dbgu_print_ascii(const char *buffer) {}

#include "DBGU.h"
#define INIT_SUCCESS 0 
#define TASK 1

int main() {
  if( initializeDGBU() == INIT_SUCCESS ) {
    
#if TASK == 1
      printAlphabet();
#endif
      
#if TASK == 2
      printString("\n\rHello world!\r\n");
#endif
      
#if TASK == 3
      while(1)
	reverseLetterCase();
#endif  
  }
  while(1);
}