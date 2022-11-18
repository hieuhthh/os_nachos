#include "syscall.h"

#define MAX_LEN_FILE_NAME 33 

int main(){
    char source_file[MAX_LEN_FILE_NAME];
    char dest_file[MAX_LEN_FILE_NAME];
    int source_id;
    int info_len;
    char read_character;
    char end_character;
    int i;
    int dest_id;
    PrintString("Enter source file name to copy contents (filename length <= 32): ");
    ReadString(source_file, MAX_LEN_FILE_NAME);

    PrintString("Enter destination file name to copy contents (filename length <= 32): ");
    ReadString(dest_file, MAX_LEN_FILE_NAME);

    // If two file source and dest are the same
    if (0)
        PrintString("The source file and destination file is the same\n");
    else {
        source_id = Open(source_file);

        if (source_id != -1){
            dest_id = Open(dest_file);        
            if (dest_id != -1){
                Close(dest_id);
                Remove(dest_file);   
            } 
            Create(dest_file);
            dest_id = Open(dest_file);
            if (dest_id == -1){
                PrintString("Failed to open destination file\n");
                Halt();
            } else {
                info_len = Seek(-1, source_id);
                Seek(0, source_id);
                for (i = 0; i < info_len; ++i){
                    Read(&read_character, 1, source_id);
                    Write(&read_character, 1, dest_id);
                }
                Close(dest_id);
            }
            Close(source_id);
        }
        else 
            PrintString("Failed to open source file\n");
    }
    
    Halt();
}