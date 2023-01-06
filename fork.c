#include"header.h"
int main()
{
	pid_t q,r;
	printf("Before fork\n");
	q=fork();
	if(q==0)
	{
		printf("q - Child process = %d\n",getpid());
		printf("q - my parent = %d\n",getppid());
		r=fork();
		if(r==0)
		{
			printf("r - Child process = %d\n",getpid());
			printf("r - my parent = %d\n",getppid());
		}
		else
		{
		sleep(5);
			printf("r - Parent process = %d\n",getpid());
			printf("r - my child = %d\n",r);
		}
	}
	else
	{
		sleep(5);
		printf("q - Parent process = %d\n",getpid());
		printf("q - my child = %d\n",q);

	}
	printf("After fork\n");
}
