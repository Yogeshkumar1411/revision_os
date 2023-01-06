#include"header.h"
void main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage:./a.out fname\n");
		return;
	}
	struct stat v;
	if(stat(argv[1],&v)<0)
	{
		perror("Stat\n");
		return;
	}
	printf("Sizeof file = %ld\n",v.st_size);
}
