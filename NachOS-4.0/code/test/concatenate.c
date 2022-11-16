#include "syscall.h"

#define MAX_LEN_FILE_NAME 33 

int main(){
    char source_file[MAX_LEN_FILE_NAME];
    char dest_file[MAX_LEN_FILE_NAME];
    int source_id;
    int info_len;
    char read_character;
    int i;
    int dest_id;
    PrintString("Enter source file name to concatenate (filename length <= 32): ");
    ReadString(source_file, MAX_LEN_FILE_NAME);

    PrintString("Enter destination file name that concatenate to (filename length <= 32): ");
    ReadString(dest_file, MAX_LEN_FILE_NAME);

    source_id = Open(source_file);

    if (source_id != -1){
        // PrintString("Source file successfully\n");
        dest_id = Open(dest_file);
        if (dest_id == -1){
            Close(dest_id);
            Close(source_id);
            PrintString("Failed to open the Destinatino file\n");
            Halt();
        } 
        info_len = Seek(-1, source_id);
        Seek(0, source_id);
        Seek(-1, dest_id);
        for (i = 0; i < info_len; ++i){
            Read(&read_character, 1, source_id);
            Write(&read_character, 1, dest_id);
        }
        Close(dest_id);
    }
    else PrintString("Failed to open source file\n");
    
    Close(source_id);
    
    Halt();
}