
//checking.........


#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
void sum()
{
	pid_t q;
	int a=10,b=10;
	fork();
	printf("sum: %d\n",a+b);
}
void sub()
{
	if(q==0)
	{
	int a=10,b=10;
	printf("sub: %d\n",a-b);
	}
}

int main()
{
	sum();
	sub();
	fork();
}
