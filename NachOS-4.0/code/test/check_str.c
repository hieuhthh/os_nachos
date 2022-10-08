#include "syscall.h"
#define endl PrintChar('\n')
int main(){
    char buffer[256]; // 255 characters and ending \0
    char buffer2[] = "InitializeString\n";
    int length;
    int cnt = 0, i;
    PrintString("PrintString, PrintChar, ReadString and ReadChar test\n");
    PrintString("Enter the string length <= 255: ");
    length = ReadNum();
    PrintString("Enter the string: ");
    ReadString(buffer, length);
    endl;
    for(i = 0; buffer[i] != '\0'; ++i){
        ++cnt;
    }
    PrintString("The actual length of the string is: ");
    PrintNum(cnt);
    endl;
    PrintString(buffer);
    endl;
    PrintString("This is a string from an initialize variable: ");
    PrintString(buffer2);
    Halt();
}