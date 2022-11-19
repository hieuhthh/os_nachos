#include "syscall.h"

#define endl PrintChar('\n')

int main(){
    char c;
    // Checking the ReadChar and PrintChar
    PrintString("Enter a character = ");
    // Read in a single character
    c = ReadChar();
    PrintString("Last entered character was = ");
    PrintChar(c);
    
    endl;
    Halt();
}