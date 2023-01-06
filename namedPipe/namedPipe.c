#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
int main()
{
	if(mkfifo("myfifo1",0777) == -1)
	{
		if(errno!=EEXIST)
		{
			printf("Could not create fifo file\n");
			return 1;
		}
	}
	while(1)
	{
		int fd = open("myfifo1",O_WRONLY);
		char x[50];
		printf("Enter the data:\n");
		scanf("%s",x);
		if(write(fd,x,strlen(x)+1) == -1)
		{
			printf("Write failed..\n");
			return 2;
		}	
		close(fd);
	
#if 1	
	char p[50];
	fd = open("myfifo1",O_RDONLY);
	if(read(fd,p,sizeof(p))==-1)
	{
		return 3;
	}
	close(fd);
	printf("\n\n\n\n From read = %s\n",p);
#endif
	}
}
