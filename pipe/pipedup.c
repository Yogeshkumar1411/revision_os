#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int p[2],q[2];
	if(pipe(p)==-1){return 1;}
	if(pipe(q)==-1){return 2;}
	printf("p0 = %d\np1 = %d\nq0 = %d\nq1 = %d\n",p[0],p[1],q[0],q[1]);
	int id=fork();	
	if(id==0)//child
	{
		close(p[1]);
		close(q[0]);
		int x;
		if(read(p[0],&x,sizeof(int)) == -1)
		{
			return 3;
		}
		printf("%d Received x = %d\n",id,x);
		x=x+10;
		if(write(q[1],&x,sizeof(int)) == -1)
		{
			return 4;
		}
		close(p[0]);
		close(q[1]);
		printf("%d wrote x = %d\n",id,x);
	}
	else//parent
	{
		close(p[0]);
		close(q[1]);
		int y=10;
		if(write(p[1],&y,sizeof(int)) == -1)
		{
			return 5;
		}
		printf("%d wrote y = %d\n",id,y);
		if(read(q[0],&y,sizeof(int)) == -1)
		{
			return 6;
		}
		close(p[1]);
		close(p[0]);
		printf("%d received y = %d\n",id,y);
		wait(NULL);
	}
}
