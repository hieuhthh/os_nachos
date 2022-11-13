#include "syscall.h"

#define MAX_LEN 256 // max_len 255 + 1
#define MAX_LEN_FILE_NAME 33 // max_len_file_name 32 + 1

int main()
{
    char buffer[] = "remove_this.txt";
    int return_value;

    return_value = Create(buffer);

    if (return_value == 0)
        PrintString("Create file successfully\n");
    else
        PrintString("Create file unsuccessfully\n");

    return_value = Remove(buffer);

    if (return_value == 0)
        PrintString("Remove file successfully\n");
    else
        PrintString("Remove file unsuccessfully\n");

    Halt();
}