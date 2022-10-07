/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"




void SysHalt()
{
  kernel->interrupt->Halt();
}


long long SysAdd(long long op1, long long op2)
{
  return op1 + op2;
}






#endif /* ! __USERPROG_KSYSCALL_H__ */
