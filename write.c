#include<stdio.h>
#include<unistd.h>
int main()
{
	int n;
	n=write(1,"Hello",5);//1 is STDOUT=monitor
	printf("value of n is %d\n",n);
}


