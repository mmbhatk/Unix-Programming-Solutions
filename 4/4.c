#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <utime.h> 
#include <time.h> 
#include <fcntl.h>

int main(int argc, char* argv[])
{
	struct stat filestat1;
	struct stat filestat2;
	struct utimbuf times;

	if(stat(argv[1], &filestat1) < 0) {fprintf(stderr, "\nstat error.\n"); exit(-1);}
	if(stat(argv[2], &filestat2) < 0) {fprintf(stderr, "\nstat error.\n"); exit(-1);}

	printf("\nBefore copying:");
	printf("\nAccess time: %s", ctime(&filestat1.st_atime));
	printf("Modification time: %s", ctime(&filestat1.st_atime));

	times.actime = filestat2.st_atime;
	times.modtime = filestat2.st_mtime;

	if(utime(argv[1], &times) < 0) {fprintf(stderr, "\nutime error.\n"); exit(-1);}
	if(stat(argv[1], &filestat1) < 0) {fprintf(stderr, "\nstat error.\n"); exit(-1);}

	printf("\nAfter copying:");
	printf("\nAccess time: %s", ctime(&filestat1.st_atime));
	printf("Modification time: %s", ctime(&filestat1.st_atime));
}

