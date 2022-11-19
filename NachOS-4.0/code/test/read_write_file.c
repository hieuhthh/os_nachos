#include "syscall.h"

#define MAX_LEN 256 // max_len 255 + 1
#define MAX_LEN_FILE_NAME 33 // max_len_file_name 32 + 1

int main()
{
    char buffer[] = "abc.txt";
    int return_value;
    int file_id;
    char info[] = "Information Technology";
    char read_str[MAX_LEN];
    int info_len = 50;


    return_value = Create(buffer);

    if (return_value == 0)
        PrintString("Create file successfully\n");
    else
        PrintString("Create file unsuccessfully\n");

    file_id = Open(buffer);
    PrintString("Open file_id: ");
    PrintNum(file_id);
    PrintChar('\n');

    // write file

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

    Close(file_id);

    // read file

    file_id = Open(buffer);

    return_value = Read(read_str, info_len, file_id);

    if (return_value == -1)
        PrintString("Read file unsuccessfully\n");
    else
    {
        PrintString("Read file successfully\n");
        PrintString("Read string: ");
        PrintString(read_str);
        PrintChar('\n');
        PrintString("Actual n_characters read: ");
        PrintNum(return_value);
        PrintChar('\n');
    }

    Close(file_id);

    Halt();
}