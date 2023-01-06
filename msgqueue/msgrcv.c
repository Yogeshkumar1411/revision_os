#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>
struct msgbuf
{
	long mtype;
	char data[20];
};
int main()
{
	int id;
	struct msgbuf v;
	id = msgget(3,IPC_CREAT | 0666);
	perror("msgget");
	printf("Before receiving the msg\n");
	msgrcv(id,&v,20,3,0);
	printf("Data = %s\n",v.data);
}
