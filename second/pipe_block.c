#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int p[2];
	int count = 0;
	char ch = 'a';
//	if(pipe(p) == -1)
//	{
//		printf("Pipe creating failed,,,\n");
//		return 1;
//	}
	pipe2(p,O_NONBLOCK);
	while(write(p[1],&ch,1)!=-1)
	{
		count++;
		printf("count = %d\n",count);
	}
	printf("Bye..\n");
}
