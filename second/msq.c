#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main()
{
	int id;
	id = msgget(3,IPC_CREAT|0666);
	if(id<0)
	{
		perror("msgget");
		return 1;
	}
	printf("id = %d\n",id);
}
