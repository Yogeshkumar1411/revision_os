
/////need to work on locking

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
	int p[2],q[2];
	if(pipe(p)<0)
	{
		return 1;
	}
	if(pipe(q)<0)
	{
		return 2;
	}
	char data[20];

	printf("p0 = %d\n p1 = %d\nq0 = %d\nq1 = %d\n",p[0],p[1],q[0],q[1]);
	int id;
	id = fork();
	if(id)
	{
		close(p[0]);
		close(q[1]);
		printf("parent Enter the data:\n");
		scanf("%s",data);
		if(write(p[1],data,strlen(data)+1) ==-1)
		{
			return 3;
		}

		printf("%d wrote %s\n",id,data);

		if(read(q[0],data,sizeof(data)) == -1)
		{
			return 4;
		}
		close(p[1]);
		close(q[0]);
		printf("%d read %s\n",id,data);
		wait(NULL);
	}
	else
	{	
		close(p[1]);
		close(q[0]);
		if(read(p[0],data,sizeof(data)) == -1)
		{
			return 5;
		}

		printf("%d read %s\n",id,buff);
		printf("child Enter the data:\n");
		scanf("%s",data);
		
		if(write(q[1],data,strlen(buff1)+1) == -1)
		{
			return 6;
		}
		close(p[0]);
		close(q[1]);
		printf("%d write %s\n",id,buff1);
//		wait(NULL);
	}
}
