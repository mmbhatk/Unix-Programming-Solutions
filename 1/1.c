#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	int i, filesize, source, dest;
	char buf;

	if(argc!=3) {fprintf(stderr, "\nUsage: %s <source> <destination>", argv[0]); exit(-1);}
	if((source = open(argv[1], O_RDONLY)) < 0) {fprintf(stderr, "\nError opening source file."); exit(-1);}
	if((dest = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC)) < 0) {fprintf(stderr, "\nError opening destination file."); exit(-1);}

	filesize = lseek(source, (off_t) 0, SEEK_END);
	printf("\nFile size: %d", filesize);

	for(i = filesize - 1; i >= 0; i--)
	{
		lseek(source, (off_t)i, SEEK_SET);
		if((read(source, &buf, 1))!=1) {fprintf(stderr, "\nError reading 1 byte."); exit(-1);}
		if((write(dest, &buf, 1))!=1) {fprintf(stderr, "\nError writing 1 byte."); exit(-1);}
	}
	printf("\nDONE.\n");
	return 0;
}
