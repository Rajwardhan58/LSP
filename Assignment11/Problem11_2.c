//write a program which creates multiple threads and sets its thread attributes accordingly.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *ThreadProc(void *ptr)
{
    printf("Inside thread %d\n",*((int *)ptr)); //*((int *)ptr)
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1=0,TID2=0,TID3=0,TID4=0;
    pthread_t *arr[]={&TID1,&TID2,&TID3,&TID4};
    int brr[]={1,2,3,4};
    int ret=0;
    for(int i=0;i<4;i++)
    {
        ret=pthread_create(arr[i],NULL,ThreadProc,&brr[i]);
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
    return 0;
}