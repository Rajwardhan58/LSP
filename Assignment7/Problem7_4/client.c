
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
int main(int argc,char *argv[])
{
    void *ptr = NULL;

    long int (*fptr)(int);
    long int ret=0;
    if(argc!=2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }
    ptr=dlopen("/home/rajwardhan58/Desktop/AssignmentLSP/Problem7_4/libOut.so",RTLD_LAZY);

    if(ptr== NULL)
    {
        printf("Unable to load liabrary\n");
        
    }
    else
    {
        fptr=dlsym(ptr,"factorialFun");
        if(fptr == NULL)
        {
            printf("Unable to load the address of function\n");
            return -1;
        }
        ret=fptr(atoi(argv[1]));
        printf("factorial : %ld\n ",ret);
        
    }
    

    
    return 0;
}