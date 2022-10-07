#include "syscall.h"

#define endl PrintChar('\n')


int main(){
    PrintString("The Random Generator outputs: ");
    PrintNum(RandomNum());
    endl;
    Halt();
}