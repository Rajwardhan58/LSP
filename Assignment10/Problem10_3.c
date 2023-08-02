//write a program which creates single thread and it accept one value from user and it return some value to the caller thread


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void  *ThreadProc(void *ptr)
{
    int val=*((int *)ptr);
    printf("Number is : %d\n",val);
    pthread_exit((++val));
}


int main()
{
    pthread_t TID;
    int ret=0;
    int retVal=0;
    int data=23;

    ret=pthread_create(&TID,NULL,ThreadProc,&data);
    if(ret!=0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    pthread_join(TID,&retVal);
    printf("Return value from thread : %d\n",retVal);


    return 0;
}