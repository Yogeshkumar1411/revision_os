#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

int main()
{
	int id;
	char *p;
	id = shmget(2,50,IPC_CREAT | 0666);
	perror("shmget");
	p = shmat(id,0,0);
	printf("data = %s\n",p);
}
