// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "main.h"
#include "syscall.h"
#include "ksyscall.h"
#include "synchconsole.h"

//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// If you are handling a system call, don't forget to increment the pc
// before returning. (Or else you'll loop making the same system call forever!)
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	is in machine.h.
//----------------------------------------------------------------------

// reference from ../machine/mipssim.cc: void Machine::OneInstruction(Instruction *instr)
// and default code from SyscallException/SC_Add



void IncreaseProgramCounter()
{
	/* set previous programm counter (debugging only)*/
	kernel->machine->WriteRegister(PrevPCReg, kernel->machine->ReadRegister(PCReg));

	/* set programm counter to next instruction (all Instructions are 4 byte wide)*/
	kernel->machine->WriteRegister(PCReg, kernel->machine->ReadRegister(PCReg) + 4);
	
	/* set next programm counter for brach execution */
	kernel->machine->WriteRegister(NextPCReg, kernel->machine->ReadRegister(PCReg) + 4);
}

void SC_Halt_Handler()
{
	DEBUG(dbgSys, "Shutdown, initiated by user program.\n");
	SysHalt();
	ASSERTNOTREACHED();
}

void SC_Add_Handler()
{
	DEBUG(dbgSys, "Add " << kernel->machine->ReadRegister(4) << " + " << kernel->machine->ReadRegister(5) << "\n");
	/* Process SysAdd Systemcall*/
	int INT_MIN = -2147483648;
	int INT_MAX = 2147483647;
	long long result;
	result = (long long)kernel->machine->ReadRegister(4) + (long long)kernel->machine->ReadRegister(5);
	if (result > INT_MAX || result < INT_MIN){
		result = 0;
		DEBUG(dbgSys, "Integer artihmetic overflow, converting the result back 0\n");
	} else
	DEBUG(dbgSys, "Add returning with " << result << "\n");
	/* Prepare Result */
	kernel->machine->WriteRegister(2, (int)result);

	/* Modify return point */
	IncreaseProgramCounter();
}

void SC_ReadNum_Handler()
{
	// min and max range of integer
	int INT_MIN = -2147483648;
	int INT_MAX = 2147483647;
	// len of INT_MIN (included '-')
	int INT_LEN_MAX = 11;
	char *str = new char[INT_LEN_MAX + 1];
	bool isNeg = false; 
	int n = 0;

	while (n <= INT_LEN_MAX)
	{
		// read from console
		char c = kernel->synchConsoleIn->GetChar(); 
		bool ok = false;
		if (c == '-' && n == 0)
		{
			ok = true;
			isNeg = true;
		}
		else if (c >= '0' and c <= '9')
			ok = true;
		if (!ok)
			break;
		str[n++] = c;
	}
	int start = 0;
	if (isNeg) 
		start = 1;
	 // starts from 1 if isNeg, 0 otherwise
	long long value = 0;
	for (int i = start; i < n; ++i)
		value = value * 10 + (str[i] - '0');	
	
	if (isNeg)
		value = -value;

	if (n > INT_LEN_MAX || value < INT_MIN || value > INT_MAX)
	{
		value = 0;
		DEBUG(dbgSys, "Integer Overflow, converting the result back 0\n");
	}
	else DEBUG(dbgSys, "ReadNum: " << value << "\n");

	delete[]str;
	kernel->machine->WriteRegister(2, value);
	IncreaseProgramCounter();
}

void SC_PrintNum_Handler()
{
	int int_num = kernel->machine->ReadRegister(4);
	long long num = (long long)int_num;

	DEBUG(dbgSys, "PrintNum: " << int_num << "\n");

	if (num == 0)
	{
		kernel->synchConsoleOut->PutChar('0');
		IncreaseProgramCounter();
		return;
	}

	if (num < 0)
	{
		kernel->synchConsoleOut->PutChar('-');
        // this is why we need long long (--2147483648 > 2147483647)
		num = -num;
	}

	// len of INT (not included '-')
	int INT_LEN_MAX = 10;
	char *str = new char[INT_LEN_MAX + 1];
	int n = 0;

	while (num)
	{
		str[n++] = (num % 10) + '0';
		num /= 10;
	}

	for (int i = n - 1; i >= 0; --i)
		kernel->synchConsoleOut->PutChar(str[i]);
	
	delete[]str;
	IncreaseProgramCounter();
}

void SC_ReadChar_Handler()
{
	char c = kernel->synchConsoleIn->GetChar();

	DEBUG(dbgSys, "ReadChar: " << c << "\n");

	kernel->machine->WriteRegister(2, (int)c);

	IncreaseProgramCounter();
}

void SC_PrintChar_Handler()
{
	char c = kernel->machine->ReadRegister(4);

	DEBUG(dbgSys, "PrintChar: " << c << "\n");

    kernel->synchConsoleOut->PutChar(c);

	IncreaseProgramCounter();
}

void SC_RandomNum_Handler()
{
	// initialization
	srandom(time(NULL)); 
	// get random number
	int num = random();

	DEBUG(dbgSys, "RandomNum: " << num << "\n");

	kernel->machine->WriteRegister(2, num);

	IncreaseProgramCounter();
}

// String Function

// Input:
// + User space address (int)
// + Limit of buffer (int)
// Output:
// + Buffer (char*)
// Purpose: 
// + Copy buffer from User memory space to System memory space
char *User2System(int virtAddr, int limit)
{
	int i; // index
	int oneChar;
	char *kernelBuf = NULL;

	kernelBuf = new char[limit + 1]; // need for terminal string
	if (kernelBuf == NULL)
		return kernelBuf;
	memset(kernelBuf, 0, limit + 1);

	for (i = 0; i < limit; i++)
	{
		kernel->machine->ReadMem(virtAddr + i, 1, &oneChar);
		kernelBuf[i] = (char)oneChar;
		if (oneChar == 0)
			break;
	}
	return kernelBuf;
}

// Input:
// + User space address (int)
// + Limit of buffer (int)
// + Buffer (char[])
// Output:
// + Number of bytes copied (int)
// Purpose: 
// + Copy buffer from System memory space to User memory space
int System2User(int virtAddr, int len, char *buffer)
{
	if (len < 0)
		return -1;
	if (len == 0)
		return len;
	int i = 0;
	int oneChar = 0;
	do
	{
		oneChar = (int)buffer[i];
		kernel->machine->WriteMem(virtAddr + i, 1, oneChar);
		i++;
	} while (i < len && oneChar != 0);
	return i;
}

void SC_ReadString_Handler()
{
	int MAX_LEN = 255;
	int addr = kernel->machine->ReadRegister(4);
	int len = kernel->machine->ReadRegister(5);

	// check if length < 0 or length too big (> MAX_LEN)
	if (len < 0 or len > MAX_LEN)
	{
		DEBUG(dbgSys, "Invalid string length\n");
		return;
	}

	char *buffer = User2System(addr, len + 1);
	int i = 0;
	
	while (true)
	{
		char c = kernel->synchConsoleIn->GetChar();

		if (i >= len || c == '\0' || c == '\n')
			break;
		
		buffer[i++] = c;
	}

	buffer[i] = '\0';

	System2User(addr, len, buffer);

	delete[]buffer;

	IncreaseProgramCounter();
}

void SC_PrintString_Handler()
{
	int MAX_LEN = 255;
	int addr = kernel->machine->ReadRegister(4);
	char *buffer = User2System(addr, MAX_LEN);

	if (!buffer)
	{
		DEBUG(dbgSys, "Buffer is NULL\n");
		IncreaseProgramCounter();
		return;
	}

	int i = 0;

	while (i < MAX_LEN && buffer[i] != '\0')
		kernel->synchConsoleOut->PutChar(buffer[i++]);

	delete[]buffer;
	
	IncreaseProgramCounter();
}

void ExceptionHandler(ExceptionType which)
{
    int type = kernel->machine->ReadRegister(2);

    DEBUG(dbgSys, "Received Exception " << which << " type: " << type << "\n");

    switch (which) 
	{
		case NoException:
            return;
		case PageFaultException:
			DEBUG('a', "\nNo valid translation found\n");
			cerr << "\nNo valid translation found\n";
			SysHalt();
            ASSERTNOTREACHED();
			break;
		case ReadOnlyException:
			DEBUG('a', "\nWrite attempted to page marked \"read-only\"\n");
			cerr << "\nWrite attempted to page marked \"read-only\"\n";
			SysHalt();
            ASSERTNOTREACHED();
			break;
		case BusErrorException:
			DEBUG('a', "\nTranslation resulted in an invalid physical address\n");
			cerr << "\nTranslation resulted in an invalid physical address\n";
			SysHalt();
            ASSERTNOTREACHED();
			break;
		case AddressErrorException:
			DEBUG('a', "\nUnaligned reference or one that was beyond the end of the address space\n");
			cerr << "\nUnaligned reference or one that was beyond the end of the address space\n";
			SysHalt();
            ASSERTNOTREACHED();
			break;
		case OverflowException:
			DEBUG('a', "\nInteger overflow in add or sub\n");
			cerr << "\nInteger overflow in add or sub\n";
			SysHalt();
            ASSERTNOTREACHED();
			break;
		case IllegalInstrException:
			DEBUG('a', "\nUnimplemented or reserved instr\n");
			cerr << "\nUnimplemented or reserved instr\n";
			SysHalt();
            ASSERTNOTREACHED();
			break;
		case NumExceptionTypes:
			DEBUG('a', "\nNumExceptionTypes\n");
			cerr << "\nNumExceptionTypes\n";
			SysHalt();
            ASSERTNOTREACHED();
			break;
    	case SyscallException:
      		switch(type) 
			{
      			case SC_Halt:
					SC_Halt_Handler();
					break;
      			case SC_Add:
					SC_Add_Handler();
					break;
				case SC_ReadNum:
					SC_ReadNum_Handler();
					break;
				case SC_PrintNum:
					SC_PrintNum_Handler();
					break;
				case SC_ReadChar:
					SC_ReadChar_Handler();
					break;
				case SC_PrintChar:
					SC_PrintChar_Handler();
					break;
				case SC_RandomNum:
					SC_RandomNum_Handler();
					break;
				case SC_ReadString:
					SC_ReadString_Handler();
					break;
				case SC_PrintString:
					SC_PrintString_Handler();
					break;
      			default:
					cerr << "Unexpected system call " << type << "\n";
					break;
			}
      		break;
    	default:
      		cerr << "Unexpected user mode exception " << (int)which << "\n";
      		ASSERTNOTREACHED();
    }
}
