#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void callback()
{
	printf("\nInterrupt received.");
	(void)signal(SIGINT, SIG_DFL);
}

int main()
{
	int choice, i = 0;
	printf("\nEnter choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1: (void)signal(SIGINT, callback); break;
		case 2: (void)signal(SIGINT, SIG_IGN); break;
	}

	while(1)
	{
		sleep(1);
		printf("\nRunning. . .");
		i++;
		if(i==10 && choice==2) (void)signal(SIGINT, SIG_DFL);
	}
	return 0;
}
