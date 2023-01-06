#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>
struct msgbuf
{
	long mtype;
	char data[20];
};
int main(int argc,char **argv)
{
	int id;
	struct msgbuf v;
	id = msgget(3,IPC_CREAT | 0666);
	perror("msgget");
	v.mtype = atoi(argv[1]);
	strcpy(v.data,argv[2]);
	printf("id = %d\n",id);
	msgsnd(id,&v,strlen(v.data)+1,0);
}
