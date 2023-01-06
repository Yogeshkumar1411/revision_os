#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<sys/ipc.h>
#include<sys/sem.h>
int main()
{
	int fd,id;
	fd = open("data.txt",O_RDWR|O_CREAT|O_APPEND,0666);
	id = semget(3,5,IPC_CREAT|0664);

	struct sembuf v;
	v.sem_num = 2;
	v.sem_op = 0;
	v.sem_flg = 0;

	printf("before\n");
	semop(id,&v,1);
	printf("After\n");

	char a;
	semctl(id,2,SETVAL,1);
	for(a=65;a<92;a++)
	{
		write(fd,&a,sizeof(char));
		sleep(1);
	}
	semctl(id,2,SETVAL,0);
	close(fd);
#if 0
	char buf[50];
	read(fd,buf,sizeof(buf));
	printf("%s\n",buf);
#endif
}
