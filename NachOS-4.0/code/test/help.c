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
    
    Halt();
}