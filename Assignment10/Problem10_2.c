// write a program which creates two thread , first thread print thread print numbers from 1 to 500 & other thread print the numbers from 500 to 1.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *ThreadProc1(void *ptr)
{
    int i=1;
    while(i<=500)
    {
        printf("%d\t",i++);
    }
    pthread_exit(NULL);
}
void *ThreadProc2(void *ptr)
{
    int i=500;
    while(i>=1)
    {
        printf("%d\t",i--);
    }
    pthread_exit(NULL);

}
int main()
{
    pthread_t TID1,TID2;
    int ret1=0,ret2=0;

    ret1=pthread_create(&TID1,NULL,ThreadProc1,NULL);
    
    if(ret1!=0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread 2 is created withb id : %lu\n",TID2);
    
    ret1=pthread_create(&TID2,NULL,ThreadProc2,NULL);

    if(ret2!=0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread 1 is created withb id : %lu\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    return 0;
}