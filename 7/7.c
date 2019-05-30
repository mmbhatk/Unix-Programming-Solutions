#include<stdio.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	if((pid = fork()) < 0) {printf("\nFork error.\n"); exit(0);}
	else if(pid == 0)
	{
		if((pid = fork()) < 0) {printf("\nFork error.\n"); exit(0);}
		else if(pid > 0) exit(0);
		sleep(2);
		printf("\nSecond child. Parent pid: %d\n", getppid());
		exit(0);
	}
	if(waitpid(pid, NULL, 0) != pid) {printf("\nwaitpid error.\n"); exit(0);}
}
