//write a program which accept user defined signal from terminal.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include<unistd.h>
#include <sys/types.h>
#include<stdlib.h>
#include <sys/wait.h>
void signal_handler(int signum) {
    printf("Received signal: %d\n", signum);
    exit(0);
}

int main() 
{
    int signal_num;
    int pid=0,status=0;
    printf("Enter a signal number: ");
    scanf("%d", &signal_num);

    if (signal_num < 1 || signal_num >= NSIG) {
        printf("Invalid signal number.\n");
        return 1;
    }

    if (signal(signal_num, signal_handler) == SIG_ERR) {
        perror("Signal setup error");
        return 1;
    }

    printf("Waiting for signal %d...\n", signal_num);
    // while (1) 
    // {
    // }
    pid=fork();

    if(pid==0)
    {
        printf("Child: Sending signal to parent.\n");
        kill(getppid(), signal_num);
        exit(0);
    }
    else
    {
        waitpid(pid, &status, 0);
        printf("Parent: Child process completed.\n");
    }

    return 0;
}
