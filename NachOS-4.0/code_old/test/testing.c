#include "syscall.h"


/**
 *  @brief Testing the error
 *  So far found out that :
 *  -   it does only open 18 files at once, for 19th file later-on will be considered as "failed to open"
 *  -   
    @return 
*/
int main(){
    char buffer[256];
    char content[32];
    int i;
    int tableID[32];
    for(i = 0; i < 20; ++i){
        PrintString("Enter the file name please: ");
        ReadString(buffer, 32);
        
        tableID[i] = Open(buffer);
        if (tableID[i] == -1){
            PrintString("File not exits, not creating new file though\n");
            
            // Create(buffer);
            // tableID[i] = Open(buffer);
            // if (tableID[i] == -1){
            //     PrintString("Failed to Create and Open the file\n");
            // } else {
            //     Write(content, 7, tableID[i]);
            //     PrintString("Open file Successfully\n");
            //     Close(tableID[i]);
            // }
        } else {
            PrintString("The file does exists, not gonna close it though\n");
        }
    }
    Halt();
}