#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include "out.h"

long int factorialFun(int no)
{
    void *ptr=NULL;
    long int (*fptr)(int);
    long int ret = 0;
    ptr=dlopen("/home/rajwardhan58/Desktop/AssignmentLSP/Problem7_4/libIn.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        
    }
    else
    {
        fptr = dlsym(ptr,"Factorial");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
        
    }
    else
    {
        ret=fptr(no);
        return ret;
    }

    }

    
}
