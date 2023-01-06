#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fdr,fdw;
	char a[100],b[100];



	/*if(mkfifo("fifofile",0666) == -1)
	{
		printf("fifo creation failed\n");
		return 1;
	}
	if(mkfifo("fifofile1",0666) == -1)
	{
		printf("fifo2 creation failed\n");
		return 1;
	}*/



	mkfifo("fifofile",0666);
	mkfifo("fifofile1",0666);
	while(1)
	{	
		fdw = open("fifofile1",O_RDWR);
		fdr = open("fifofile",O_RDWR);
		printf("process 1...\n");
		printf("(p1) enter the data to write...\n");
		gets(a);
		if(write(fdw,a,strlen(a)+1) == -1)
		{
			printf("write failed\n");
			return 3;
		}

		bzero(b,sizeof(b));//initialize tthe array with zero
		if(read(fdr,b,sizeof(b)) == -1)
		{
			printf("Read failed\n");
			return 4;
		}
		close(fdw);
		close(fdr);
		printf("from p2 = %s\n",b);

	}
#ifdef simplex
	do
	{
		printf("Process 1\n");
		printf("Enter the data..\n");
		scanf("%s",a);
		if(write(fd,a,strlen(a)+1) == -1)
		{
			return 2;
		}
	}while(1);
#endif
}

