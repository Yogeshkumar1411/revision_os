#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main()
{
	int n;
	n=fork();
	if(n==0)
	{
		execl("/bin/ls","ls","-l",NULL);
		printf("Child process\n");

	}
	else
	{
		printf("Parent process\n");
	}
}
