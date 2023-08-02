//write a program which creates two thread and by using appropriate synchronization techique avoid a scheduling problem

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int Num=0;
pthread_mutex_t mutex;

void *ThreadProc(void *ptr)
{
    for(int i=0;i<10000;i++)
    {
        pthread_mutex_lock(&mutex);
        Num++;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1=0,TID2=0;
    pthread_mutex_init(&mutex,NULL);
    int ret1=0,ret2=0;
    
        ret1=pthread_create(&TID1,NULL,ThreadProc,NULL);
        if(ret1!=0)
        {
            return -1;
        }

        ret2=pthread_create(&TID2,NULL,ThreadProc,NULL);
        if(ret2!=0)
        {
            return -1;
        }

        pthread_join(TID1,NULL);
        pthread_join(TID2,NULL);
        pthread_mutex_destroy(&mutex);
     printf("value in Num : %d\n",Num);
    return 0;
}