#include "syscall.h"

#define MAX_LEN_FILE_NAME 33 
#define MAX_LEN 256

int main(){
    char buffer[MAX_LEN_FILE_NAME];
    int return_value;
    int file_id;
    char read_character;
    int info_len;
    int i;
    PrintString("Enter filename to print out the file content (filename length <= 32): ");
    ReadString(buffer, MAX_LEN_FILE_NAME);

    // read file

    file_id = Open(buffer);
    // Để lấy ra được kích thước của file cần phải cat
    info_len = Seek(-1, file_id);
    // Đưa buffer về lại đầu file để thực hiện việc đọc lại.
    Seek(0, file_id);
    for (i = 0; i < info_len; ++i){
        Read(&read_character, 1, file_id);
        PrintChar(read_character);
    }
    PrintChar('\n');
    Close(file_id);
    Halt();
}