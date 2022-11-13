#include "syscall.h"

#define MAX_LEN 256 // max_len 255 + 1
#define MAX_LEN_FILE_NAME 33 // max_len_file_name 32 + 1

int main()
{
    char buffer[] = "test_file.txt";
    int return_value;
    int file_id;
    char read_str[MAX_LEN];
    int info_len = 11;

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
    }

    return_value = Seek(info_len, file_id);

    if (return_value == -1)
        PrintString("Seek file unsuccessfully\n");
    else PrintString("Seek file successfully\n");

    return_value = Read(read_str, info_len, file_id);

    if (return_value == -1)
        PrintString("Read file unsuccessfully\n");
    else
    {
        PrintString("Read file successfully\n");
        PrintString("Read string: ");
        PrintString(read_str);
        PrintChar('\n');
    }

    Close(file_id);

    Halt();
}