#include "syscall.h"

#define endl PrintChar('\n')

int main()
{

    int a, b, c;
    char buffer[6];
    int length = 5;
    char buffer2[] = "adshakjshdakd\n";
    
    // ReadNum, Add, PrintNum test.
    PrintString("ReadNum, Add and PrintNum testing\n");
    PrintString("Enter the number a = ");
    a = ReadNum();
    PrintString("Enter the number b = ");
    b = ReadNum();
    PrintString("The value c = a + b = ");
    c = Add(a, b);
    PrintNum(c);
    endl;
    
    // PrintString, PrintChar, ReadString, ReadChar test

    PrintString("PrintString, PrintChar, ReadString and ReadChar test\n");
    ReadString(buffer, length);
    endl;
    PrintString(buffer);
    endl;
    PrintString(buffer2);
    Halt();
}