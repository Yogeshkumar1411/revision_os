#include"header.h"
int main(){
	int n,fd,fd1;
	char buf[50];
	fd=open("test.txt",O_RDONLY);
	n=read(fd,buf,50);
	fd1=open("target",O_CREAT|O_WRONLY,0666);
	write(fd1,buf,n);
}
