#include<sys/types.h>
#include<sys/shm.h>
#include<stdio.h>

int main()
{
	int id;
	char *p;
	id = shmget(2,50,IPC_CREAT|0666);
	perror("shmge");
	printf("id = %d\n",id);
	p=shmat(id,0,0);
	printf("Enter the string:\n");
	scanf("%s",p);
}
