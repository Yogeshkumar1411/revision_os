#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
int main()
{
	int p[2];
	int id;
	if(pipe(p) == -1)
	{
		printf("Error creating pipe\n");
		return 1;
	}
	id = fork();
	if(id == 0)
	{
		char s1[20];
		printf("Child before read...\n");
		read(p[0],s1,sizeof(s1));
		printf("Child after read S1 = %s\n",s1);
	}
	else
	{
		char s[20];
		printf("Parent:\nEnter the data..\n");
		scanf("%s",s);
		write(p[1],s,strlen(s)+1);
		wait(NULL);
	}

}
