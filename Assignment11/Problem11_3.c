//write a program which is used to predict the problem due to lack of synchronization.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int Num=0;

void *ThreadProc(void *ptr)
{
    for(int i=0;i<10000;i++)
    {
    Num++;

    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1=0,TID2=0,TID3=0,TID4=0;
    pthread_t *arr[]={&TID1,&TID2,&TID3,&TID4};
    int ret=0;
    for(int i=0;i<4;i++)
    {
        ret=pthread_create(arr[i],NULL,ThreadProc,NULL);
        if(ret!=0)
        {
            return -1;
        }
        //pthread_join(*(arr[i]),NULL);

    }

     for(int i=0;i<4;i++)
     {
        pthread_join(*(arr[i]),NULL);
     }

     printf("value in Num : %d\n",Num);
    return 0;
}