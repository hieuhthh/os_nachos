#include "syscall.h"


int main(){
    char buffer[] = "hello_2.txt";
    char read_character;
    int file_id;
    file_id = Open(buffer);
    
    Halt();
}