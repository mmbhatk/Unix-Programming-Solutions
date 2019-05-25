#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

static void charatatime(char* str)
{
	int i;
	setbuf(stdout, NULL);
	for(i = 0; i < strlen(str); i++)
		printf("%c", str[i]);
}

int main()
{
	pid_t pid;
	if((pid = fork()) < 0) printf("\nFork error.");
	else if(pid == 0) charatatime("Output from child\n");
	else charatatime("Output from parent\n");
}
