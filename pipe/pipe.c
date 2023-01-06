#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd[2];
	if(pipe(fd)<0)
	{
		return 1;
	}
	char data[10];

	printf("fd0 = %d \n fd1 = %d\n",fd[0],fd[1]);
	if(fork())
	{
//		char data[10];
		printf("Enter the data:\n");
		scanf("%s",data);
		write(fd[1],data,strlen(data)+1);
	}
	else
	{
		char buff[10];
		read(fd[0],buff,sizeof(data));
		printf("%s\n",buff);
	}
}
