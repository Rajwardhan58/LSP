//write a program which is used to get thread id inside its thread function


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *ThreadProc(void *ptr)
{
    printf("Inside thread\n");
    pthread_t threadId=pthread_self();
    printf("Thread Id : %lu\n",threadId);

    pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int ret=0;

    ret=pthread_create(&TID,NULL,ThreadProc,NULL);

    if(ret!=0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID,NULL);
    return 0;
}