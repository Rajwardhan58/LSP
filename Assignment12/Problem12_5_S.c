//write a program which performs interprocess communication using the concept of message queue.

//server 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>

#define TEXTSIZE 512

struct msg_st
{
    long int msg_type;
    char some_text[TEXTSIZE];
};

int main()
{
    int running = 1;
    struct msg_st some_data;
    int msgid;
    char buffer[BUFSIZ];

    msgid = msgget( (key_t)1234,0666 | IPC_CREAT);

    if (msgid == -1)
    {
        fprintf(stderr, "failed to create:\n");
        exit(EXIT_FAILURE);
    }
    while(running)
    {
        printf("Enter Some Text: ");
        fgets(buffer, BUFSIZ, stdin);
        some_data.msg_type = 1;
        strcpy(some_data.some_text, buffer);

        if(msgsnd(msgid, (void *)&some_data, TEXTSIZE, 0) == -1)
        {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        if(strncmp(buffer, "end", 3) == 0)
        {
            running = 0;
        }
    }
    exit(EXIT_SUCCESS);
}

