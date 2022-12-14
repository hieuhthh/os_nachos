#include "syscall.h"

int main() 
{
    PrintString("************************************************************************\n");
    PrintString("*******************    HCMUS - 20TN                  *******************\n");
    PrintString("******************* 20120081 - Nguyen Mau Trong Hieu *******************\n");
    PrintString("******************* 20120504 - Nhan Gia Kham         *******************\n");
    PrintString("******************* 20120599 - Phu Thi Kim Trang     *******************\n");
    PrintString("************************************************************************\n");
    PrintChar('\n');

    PrintString("Program ASCII:\n");
    PrintString("Change directory to NachOS-4.0/code/test\n");
    PrintString("Run ../build.linux/nachos -x ascii\n");
    PrintString("The program will print the ASCII table\n");
    PrintChar('\n');

    PrintString("Program Sort:\n");
    PrintString("Change directory to NachOS-4.0/code/test\n");
    PrintString("Run ../build.linux/nachos -x bubblesort\n");
    PrintString("Input:\n");
    PrintString("   Enter n (int) - the size of array (1 <= n <= 100)\n");
    PrintString("   Enter n elements in the array (each element is an int)\n");
    PrintString("   Enter type (int) - the way to sort the array\n");
    PrintString("       0: ascending order\n");
    PrintString("       1: descending order\n");
    PrintString("The program will bubble sort the array by your order and print it\n");
    PrintChar('\n');

    PrintString("Program Cat:\n");
    PrintString("Change directory to NachOS-4.0/code/test\n");
    PrintString("Run ../build.linux/nachos -x cat\n");
    PrintString("The program will ask the source file name that want to cat out the file content\n");
    PrintString("Input:\n");
    PrintString("   Enter filename to print out the file content (filename length <= 32): \n");
    PrintString("The program will try to print out the file contents (if it exists).\nIf the file not exists, the program will alert user\n");
    PrintChar('\n');

    PrintString("Program Copy:\n");
    PrintString("Change directory to NachOS-4.0/code/test\n");
    PrintString("Run ../build.linux/nachos -x copy\n");
    PrintString("The program will ask the source file name that want to copy the file content, copying it to another destination file\n");
    PrintString("Input:\n");
    PrintString("   Enter source file name to copy contents (filename length <= 32): \n");
    PrintString("   Enter destination file name to copy contents (filename length <= 32): \n");
    PrintString("The program will try to copy the file contents (if it exists) to the destination file.\nIf the file not exists, the program will alert user\n");
    PrintChar('\n');

    PrintString("Program Delete:\n");
    PrintString("Change directory to NachOS-4.0/code/test\n");
    PrintString("Run ../build.linux/nachos -x delete\n");
    PrintString("The program will ask the source file name that want to delete\n");
    PrintString("Input:\n");
    PrintString("   Enter source file name to remove (filename length <= 32): \n");
    PrintString("The program will try to delete the file (if it exists).\nIf the file not exists, the program will alert user\n");
    PrintChar('\n');
    
    Halt();
}