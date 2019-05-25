#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

void daemonize()
{
	pid_t pid = fork();
	if(pid < 0) fprintf(stderr, "\nFork error.");
	else if(pid)
	{
		printf("\nPID of child: %d\n", pid);
		exit(0);
	}

	umask(0);
	if(chdir("/") < 0) printf("\nError changing directory.\n");
	if(setsid() < 0) printf("\nError creating session.\n");

	printf("\nDaemon created.");
}

int main()
{
	daemonize();
	system("ps -axj");
	return 0;
}
