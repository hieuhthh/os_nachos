#include "syscall.h"

#define endl PrintChar('\n')

int main()
{

    int a, b, c;
    
    
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
    
    Halt();
    
}