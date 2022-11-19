#include "syscall.h"

#define endl PrintChar('\n')


int main(){
    PrintString("The Random Generator outputs: ");
    // Generate a random integer number.
    PrintNum(RandomNum());
    endl;
    Halt();
}