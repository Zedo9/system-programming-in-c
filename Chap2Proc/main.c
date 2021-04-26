#include <stdio.h>
#include <stdlib.h>
void main()
{
	int p;
	switch (p = fork())
	{
	case 1:
		perror("Error");
		exit(-1);
	case 0:
		sleep(2);
		printf("\n CHILD : My pid %d", getpid());
		printf("\n CHILD : Pid of my Parent %d", getppid());
		exit(0);
	default:
		printf("\n Parent : My pid %d", getpid());
		printf("\n Parent : Pid of my Child %d", p);
		printf("\n Parent : Pid of my Parent %d", getppid());
		sleep(2);
		exit(0);
	}
}
