#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main()
{
	char a[100],b[100];
	int fdw,fdr,id;


	fdw = open("full_fifo1",O_RDWR);
	fdr = open("full_fifo",O_RDWR);
	id = fork();
	if(id == 0)
	{
		while(1)
		{
			printf("process 2 writing...\n");
			gets(a);
			write(fdw,a,strlen(a)+1);
			printf("process 2 written...\n");
		}
	}
	else
	{
		while(1)
		{
			printf("process 1 reading...\n");
			read(fdr,b,sizeof(b));
			printf("process 2 after reading ...\n data from p1 = %s\n",b);
		}
	}
}
