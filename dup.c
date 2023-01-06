#include"header.h"
int main()
{
	int fd,fd1,fd2,n;
	char buff[20];
	fd=open("target",O_RDONLY);
	printf("fd = %d\n",fd);
	fd1=dup(fd);//it will give next file descriptor
	fd2=dup2(fd,10);//manually allocationg the file descripor
	printf("fd1 = %d\n",fd1);
	printf("fd2 = %d\n",fd2);
	n=read(fd1,buff,10);
	write(1,buff,n);
	printf("\n");
}
