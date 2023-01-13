#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
struct msgbuf
{
	long mtype;
	char data[20];
};

int main(int argc,char **argv)
{
	int id;
	if(argc!=2)
	{
		printf("Invalid format\n");
		printf("should bd ex: /.rcv 2\n");
		return 1;
	}
	struct msgbuf v;
	id = msgget(3,IPC_CREAT|0666);
	if(id<0)
	{
		perror("msgget");
		return 2;
	}
	printf("id  = %d\n",id);

	msgrcv(id,&v,sizeof(v),atoi(argv[1]),0);
	printf("msg: %s\n",v.data);
}
