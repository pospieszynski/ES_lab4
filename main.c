void dbgu_print_ascii(const char *buffer) {}

#include "DBGU.h"

void printAlphabet() {
 int letter = 'a';
 sendCharacter('P');
 while( letter <= (int)'Z' ) {
   sendCharacter('K');
   sendCharacter((char)letter);
   (int)letter++;
 }
}

int main() {
  if( initialize(8, 1, 0) == 0 ) {
    printAlphabet();
  }
  while(1){} 
}