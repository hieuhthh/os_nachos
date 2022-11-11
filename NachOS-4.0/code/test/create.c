#include "syscall.h"

#define MAX_LEN_FILE_NAME 33 // max_len_file_name 32 + 1

int main()
{
    char buffer[MAX_LEN_FILE_NAME];
    int return_value;

    PrintString("Enter filename to create (filename length <= 32): ");
    ReadString(buffer, MAX_LEN_FILE_NAME);

    return_value = Create(buffer);

    if (return_value == 0)
        PrintString("Create file successfully\n");
    else
        PrintString("Create file unsuccessfully\n");

    Halt();
}