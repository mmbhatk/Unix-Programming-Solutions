  
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<utime.h>
#include<time.h>
#include<fcntl.h>

int main()
{
	struct stat statfile;
	struct utimbuf times;

	umask(0600);

	if(creat("source.txt", 0666) < 0)
	{
		printf("Error.");
		return 0;
	}

	stat("source.txt", &statfile);
	times.actime = statfile.st_atime;
	times.modtime = statfile.st_mtime;
	utime("source.txt", &times);

	printf("\n\n%s\n%s", ctime(&times.actime), ctime(&times.modtime));
	printf("\n\n%s\n%s", ctime(&statfile.st_atime), ctime(&statfile.st_mtime));
}
