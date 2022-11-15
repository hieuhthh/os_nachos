#include "syscall.h"

#define MAX_LEN_FILE_NAME 33 

int main(){
    char source_file[MAX_LEN_FILE_NAME];
    int source_id;
    PrintString("Enter source file name to remove (filename length <= 32): ");
    ReadString(source_file, MAX_LEN_FILE_NAME);

    source_id = Open(source_file);
    if (source_id == -1){
        Close(source_id);
        PrintString("File not exists!!\n");
    } else {
        Close(source_id);
        Remove(source_file);
    }
    Halt();
}