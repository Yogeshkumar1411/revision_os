#include"header.h"
int main(){

	int fd,n;
	char buff[50];
	fd=open("target",O_RDONLY);
	n=read(fd,buff,5);
	write(1,buff,n);
	printf("\n");
	lseek(fd,-10,SEEK_END);
	n=read(fd,buff,5);
	write(1,buff,n);
	printf("\n");
}
