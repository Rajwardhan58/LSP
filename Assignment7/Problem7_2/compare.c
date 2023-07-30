//write a program which is used to create shared library and that library should be loaded at run time by the other program.

//That library should contains function which accept 2 file names from user and it will compare the contents of that file.

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc,char *argv[])
{
    void *ptr = NULL;
    int (*fptr)(char*,char*);
    int ret=0;
    if(argc!=3)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    ptr=dlopen("/home/rajwardhan58/Desktop/AssignmentLSP/Problem7_2/library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }
    fptr=dlsym(ptr,"CompareFile");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    ret=fptr(argv[1],argv[2]);
    printf("ret : %d\n",ret);
    if(ret==1)
    {
        printf("Content in the file is equal\n ");
    }
    else
    {
        printf("Content in the file is not equal\n ");
    }
    return 0;
}