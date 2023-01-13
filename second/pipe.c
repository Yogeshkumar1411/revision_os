#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main()
{
	int fd[2],fd1[2];
	int id;
	pipe(fd);
	pipe(fd1);
	id = fork();
	
	if(id == 0)
	{
		while(1)
		{
		char buff[50];
		close(fd[1]);
		close(fd1[0]);
		read(fd[0],buff,sizeof(buff));
		printf("read = %s\n",buff);
		
		bzero(buff,sizeof(buff));
		printf("Enter the data...\n");
		gets(buff);
		write(fd1[1],buff,strlen(buff)+1);
		close(fd[0]);
		close(fd1[1]);
		}
	}
	else
	{
		while(1)
		{
		char buff[50];
		close(fd[0]);
		close(fd1[1]);
		printf("Enter the data\n");
		gets(buff);
		write(fd[1],buff,strlen(buff)+1);
		
		read(fd1[0],buff,sizeof(buff));
		printf("read.... = %s\n",buff);

		close(fd[1]);
		close(fd1[0]);

		}
		
	}
	
}
