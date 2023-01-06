#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fdw,fdr;
	char a[100],b[100];
	while(1)
	{
		fdw = open("fifofile",O_RDWR);
		fdr = open("fifofile1",O_RDWR);
		printf("process 2...\n");
		bzero(b,sizeof(b));
		if(read(fdr,b,sizeof(b)) == -1)
		{
			printf("Read failed\n");
			return 1;
		}
		printf("form p1 = %s\n",b);

		
		printf("(p2) enter the data to write...\n");
		gets(a);
		if(write(fdw,a,strlen(a)+1) == -1)
		{
			printf("Write failed\n");
			return 2;
		}
		close(fdw);
		close(fdr);
#ifdef simplex
	do
	{
		printf("Process 2\n");
		if(read(fd,a,sizeof(a)) == 1)
		{
			return 1;
		}
		printf("received data = %s\n",a);
	}while(1);
#endif
}
}
