#include "syscall.h"

#define endl PrintChar('\n')

int main()
{
    int a, b, c;
    // ReadNum, Add, PrintNum test.
    PrintString("ReadNum, Add and PrintNum testing\n");
    PrintString("Enter the number a = ");
    // Read in the number for variable a
    a = ReadNum();
    PrintString("Enter the number b = ");
    // Read in the number for variable b
    b = ReadNum();
    PrintString("The value c = a + b = ");
    // Adding two variables a and b
    c = Add(a, b);
    // Printing out the value c
    PrintNum(c);
    endl;
    
    Halt();
    
}