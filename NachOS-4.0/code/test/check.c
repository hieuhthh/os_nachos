#include "syscall.h"

int main()
{
    int a, b, c;
    a = 2;
    b = 3;
    c = Add(a, b);
    a = 4;
    c = 7;
    b = Add(a, c);
    Halt();
}