#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fdw;
	char a[100];
	printf("Process write...\n");
	while(1)
	{
		fdw = open("fifofile",O_RDWR);
		printf("enter data...\n");
		scanf("%s",a);
		if(write(fdw,a,sizeof(a)) == -1)
		{
			printf("write failed .....\n");
			return 1;
		}
		close(fdw);

	}
}

