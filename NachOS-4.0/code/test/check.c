#include "syscall.h"

int main()
{
    char c = 'a';
    PrintChar(c);
    c = ReadChar();
    PrintChar(c);
    Halt();
}