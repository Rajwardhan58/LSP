//write a program which is used to create shared library and that library should be loaded at run time by the other program.

//The library should contains functions to perform the arithmatic operation like addition,subtraction, division and multiplication.


#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc,char *argv[])
{
    void *ptr = NULL;
    int (*fptr)(int,int);
    int ret=0;
    if(argc<3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    ptr=dlopen("/home/rajwardhan58/Desktop/AssignmentLSP/Problem7_1/library.so",RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr=dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    ret=fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Addition is : %d\n",ret);

    fptr = dlsym(ptr,"Subtraction");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    ret=fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Subtraction is : %d\n",ret);

    fptr=dlsym(ptr,"Multiplication");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    ret=fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Multiplication is : %d\n",ret);

    fptr = dlsym(ptr,"Division");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    ret=fptr(atoi(argv[1]),atoi(argv[2]));
    printf("Division is : %d\n",ret);

    return 0;
}