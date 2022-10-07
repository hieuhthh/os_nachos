#include "syscall.h"

int main()
{
    int a, b, c;
    // Thử nghiệm hàm ReadNum, Add, PrintNum
    a = ReadNum();
    b = ReadNum();
    c = Add(a, b);
    PrintNum(c);
    Halt();
}