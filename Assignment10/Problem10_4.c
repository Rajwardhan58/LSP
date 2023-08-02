//write a program which create single thread and we have to pass parameter to that thread from main thread.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void  *ThreadProc(void *ptr)
{
    printf("Number is : %d\n",*((int *)ptr));
}


int main()
{
    pthread_t TID;
    int ret=0;
    int data=23;

    ret=pthread_create(&TID,NULL,ThreadProc,&data);
    if(ret!=0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    pthread_join(TID,NULL);

    return 0;
}