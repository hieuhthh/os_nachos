#include "syscall.h"

int main()
{
    int a;
    int b;
    int c;

    a = ReadNum();
    // PrintNum(a);
    
    b = ReadNum();
    // PrintNum(b);
    c = a + b;
    PrintNum(c);
    Halt();
}