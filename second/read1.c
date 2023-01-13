#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fdr;
	char a[100];
	printf("read 1\n");
	while(1)
	{
	
		fdr = open("fifofile",O_RDWR);
		if(read(fdr,a,sizeof(a)) == -1)
		{
			printf("read failed...\n");
			return 1;
		}
		close(fdr);
		printf("read  = %s\n",a);
	}
}
