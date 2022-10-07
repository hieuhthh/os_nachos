#include "syscall.h"

#define MAX_SIZE 100

void swap(int* x, int* y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
 
// bubble sort array with type
// type == 0 -> ascending order
// type == 1 -> descending order
void bubbleSort(int a[], int n, int type)
{
    int i, j;
    for (i = 0; i < n - 1; ++i)
        for (j = 0; j < n - i - 1; ++j)
            if ((type == 0 && a[j] > a[j + 1]) || (type == 1 && a[j] < a[j + 1]))
                swap(&a[j], &a[j + 1]);
}

void printArray(int a[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        PrintNum(a[i]);
        PrintChar(' ');
    }
}

int main() 
{
    int n, type;
    int a[MAX_SIZE];
    int i;

    PrintString("Enter n - size of array (1 <= n <= 100): ");
    n = ReadNum();

    if (n < 1 || n > 100)
    {
        PrintString("Invalid size\n");
        Halt();
    }

    for (i = 0; i < n; i++)
    {
        PrintString("Enter a[");
        PrintNum(i+1);
        PrintString("]: ");

        a[i] = ReadNum();
    }

    PrintString("Enter type - the way to sort the array\n");
    PrintString("       0: ascending order\n");
    PrintString("       1: descending order\n");
    PrintString("Type: ");
    type = ReadNum();

    if (type != 0 && type != 1)
    {
        PrintString("Invalid type\n");
        Halt();
    }

    PrintString("Input array:\n");
    printArray(a, n);
    PrintString("\nSorted array:\n");
    bubbleSort(a, n, type);
    printArray(a, n);
    PrintChar('\n');

    Halt();
}