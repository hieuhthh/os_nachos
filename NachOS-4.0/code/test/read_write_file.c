#include "syscall.h"

#define MAX_LEN_FILE_NAME 33 // max_len_file_name 32 + 1

int main()
{
    char buffer[] = "abc.txt";
    int return_value;
    int file_id;
    char info[] = "Information Technology";
    int info_len = 50;

    PrintString("Enter filename to create (filename length <= 32): ");
    ReadString(buffer, MAX_LEN_FILE_NAME);

    return_value = Create(buffer);

    if (return_value == 0)
        PrintString("Create file successfully\n");
    else
        PrintString("Create file unsuccessfully\n");

    file_id = Open(buffer);
    PrintString("Open file_id: ");
    PrintNum(file_id);
    PrintChar('\n');

    return_value = Write(info, info_len, file_id);

    if (return_value == -1)
        PrintString("Write file unsuccessfully\n");
    else
    {
        PrintString("Write file successfully\n");
        PrintString("Actual n_characters written: ");
        PrintNum(return_value);
        PrintChar('\n');
    }

    Halt();
}