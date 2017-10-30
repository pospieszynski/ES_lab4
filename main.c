void dbgu_print_ascii(const char *buffer) {}

#include "DBGU.h"
#define TASK_1 0
#define TASK_2 0
#define TASK_3 1

int main() {
  if( initialize(8, 1, 0) == 0 ) {
    #if TASK_1
      printAlphabet();
    #endif
      
    #if TASK_2
      printBuffer("\n\rHello world!\r\n");
    #endif
      
    #if TASK_3
      while(1) {
	reverseString();
      }
    #endif
      
  }
  while(1){} 
}