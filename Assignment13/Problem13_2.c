//write a program which creates child process and parent process will communicate with child process by sending signals.

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include <sys/types.h>
#include<stdlib.h>
#include <sys/wait.h>
void sig_handler(int signo)
{
    if(signo == SIGINT)
    {
    printf("received SIGINT\n");
    }
    printf("Received signal is %d\n",signo);
}

int main()
{
    int pid=0;
    int status=0;

    signal(SIGINT,sig_handler);

    pid=fork();


    if(pid==-1)
    {
        printf("cant create process... \n");
        return -1;
    }

    if(pid==0)
    {
        printf("Child: Sending SIGINT signal to parent.\n");
        kill(getppid(), SIGINT);
        exit(0);
    }
    else
    {
        printf("Parent: Waiting for child to complete.\n");
        waitpid(pid, &status, 0);
        printf("Parent: Child process completed.\n");
    }

    return 0;
}