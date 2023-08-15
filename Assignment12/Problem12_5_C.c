
// Client
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

#include<sys/msg.h>
struct msg_st
{
	long int msg_type;
	char some_text[BUFSIZ];
};

int main()
{
	int running = 1;
	int msgid;
	struct msg_st some_data;
	long int msg_to_receive = 0;

	msgid = msgget( (key_t)1234,0666);

	while(running)
	{
		msgrcv(msgid, (void*)&some_data,BUFSIZ,msg_to_receive,0);

		printf("You Wrote: %s",  some_data.some_text);
		if(strncmp(some_data.some_text, "end", 3)== 0)
		{
			running = 0;
		}
	}

	exit(EXIT_SUCCESS);
}