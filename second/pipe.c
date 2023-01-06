#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main()
{
	int fd[2];
	int id;
	pipe(fd);
	id = fork();
	if(id == 0)
	{
		char buff[50];
		close(fd[1]);
		read(fd[0],buff,sizeof(buff));
		close(fd[0]);
		printf("read = %s\n",buff);
	}
	else
	{
		char buff[50];
		close(fd[0]);
		printf("Enter the data\n");
		gets(buff);
		write(fd[1],buff,strlen(buff)+1);
		wait(NULL);
	}
}
