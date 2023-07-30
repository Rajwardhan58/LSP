
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>
int main(int argc,char *argv[])
{
    void *ptrToPrime = NULL;
    void *ptrToPerfect = NULL;

    bool (*fptr)(int);
    bool ret=false;
    if(argc!=2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    ptrToPrime=dlopen("/home/rajwardhan58/Desktop/AssignmentLSP/Problem7_3/libPrime.so",RTLD_LAZY);
    ptrToPerfect=dlopen("/home/rajwardhan58/Desktop/AssignmentLSP/Problem7_3/libPerfect.so",RTLD_LAZY);

    if(ptrToPrime == NULL)
    {
        printf("Unable to load liabrary\n");
        
    }
    else
    {
        fptr=dlsym(ptrToPrime,"Prime");
        if(fptr == NULL)
        {
            printf("Unable to load the address of function\n");
            return -1;
        }
        ret=fptr(atoi(argv[1]));
        if(ret==true)
        {
            printf("number is prime\n ");
        }
        else
        {
            printf("number is not prime\n ");
        }
    }
    if(ptrToPerfect == NULL)
    {
        printf("Unable to load liabrary\n");
        
    }
    else
    {
        fptr=dlsym(ptrToPerfect,"Perfect");
        if(fptr == NULL)
        {
            printf("Unable to load the address of function\n");
            return -1;
        }
        ret=fptr(atoi(argv[1]));
        if(ret==true)
        {
            printf("number is perfect\n ");
        }
        else
        {
            printf("number is not perfect\n ");
        }
    }

    // free(ptrToPerfect);
    // free(ptrToPrime);
    // free(fptr);
    return 0;
}