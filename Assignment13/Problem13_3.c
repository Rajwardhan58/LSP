//write a program which creates such a process which accept signals from the terminal

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void signal_handler(int sigma)
{
    printf("Received signal...\n");
    exit(sigma);
}

int main()
{
    signal(SIGINT,signal_handler);

    while(1)
    {
        
    }
    return 0;
}