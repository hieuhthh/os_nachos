#include "syscall.h"

#define endl PrintChar('\n')

int main(){
    char c;
    PrintString("Enter a character = ");
    c = ReadChar();
    PrintString("Last entered character was = ");
    PrintChar(c);
    
    endl;
    Halt();
}