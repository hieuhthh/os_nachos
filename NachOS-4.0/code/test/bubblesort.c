#include "syscall.h"

int main()
{
    int n, a[101], i;

    PrintString("Enter the number of elements n (1 <= n <= 100): ");
    n = ReadNum();
    for (i = 1; i <= n; ++i) {
        PrintString("Enter the a[");
        PrintNum(i);
        PrintString("]: ");
        a[i] = ReadNum();    
    }
    for (i = 1; i <= n; ++i){
        PrintString("The value of a[");
        PrintNum(i);
        PrintString("]: ");
        PrintNum(a[i]);
        PrintString("\n");
    }
    
    Halt();
}