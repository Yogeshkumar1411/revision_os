#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	char a[100],b[100];
	int fdw,fdr,id;
	mkfifo("full_fifo",0666);
	mkfifo("full_fifo1",0666);

	fdw = open("full_fifo",O_RDWR);
	fdr = open("full_fifo1",O_RDWR);
	id = fork();
	if(id == 0)
	{
		while(1)
		{
			printf("process 1 reading....\n");
			read(fdr,b,sizeof(b));
			printf("Process 1 after reading...\n data from p2 = %s\n",b);
		}
	}
	else
	{
		while(1)
		{
			printf("Process 1 writing ... \n");
			gets(a);
			write(fdw,a,strlen(a)+1);
			printf("process 1 written...\n");
		}
	}
}

