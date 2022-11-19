#include "syscall.h"

int main() 
{
    // printable ASCII characters from 32 to 126
    int i;
    for (i = 32; i <= 126; ++i) 
    {
        PrintNum(i);
        PrintString(": ");
        PrintChar((char)i);
        PrintChar('\n');
    }
    Halt();
}