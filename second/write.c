#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	close(1);
	int fd = open("data",O_WRONLY|O_CREAT,0664);
	int a[5] = {10,20,30,40,50}; 
	if(fd<0)
	{
		perror("Open");
		return 1;
	}
	printf("Hello india fd = %d\n",fd);
	for(int i = 0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
