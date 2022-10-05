#include "syscall.h"

int main()
{
    int a, b, c;
    a = 2;
    b = 3;
    a = ReadNum();
    b = ReadNum();
    c = Add(a, b);
    // PrintNum(c);
    Halt();
}