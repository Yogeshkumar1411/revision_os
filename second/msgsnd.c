#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>

struct msgbuf
{
	long mtype;
	char data[20];
};

int main(int argc,char **argv)
{
	int id;
	if(argc!=3)
	{
		printf("Invalid format\n");
		printf("should be ex: ./snd 2 hello\n");
		return 1;
	}
	struct msgbuf v;
	id = msgget(3,IPC_CREAT|0666);
	if(id<0)
	{
		perror("msgget");
		return 2;
	}
	printf("id = %d\n",id);
	v.mtype = atoi(argv[1]);
	strcpy(v.data,argv[2]);
	msgsnd(id,&v,strlen(v.data)+1,0);

}

