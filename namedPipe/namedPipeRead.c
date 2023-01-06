#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	while(1)
	{
		int fd = open("myfifo1",O_RDONLY);
		char ptr[50];
		if(read(fd,ptr,sizeof(ptr)) == -1)
		{
			return 1;
		}
		close(fd);
		printf("Copied data = %s\n",ptr);
	
#if 1
	char *p = "Bitsilica";
	int len = strlen(p);
	printf("len = %d\n",len);
	fd = open("myfifo1",O_WRONLY);
	if(write(fd,p,len+1) == -1)
	{
		return 2;
	}
	close(fd);
#endif
	}
}

