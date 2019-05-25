#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main()
{
	int file;
	DIR* dp;
	struct dirent* dir;

	dp = opendir(".");

	if(dp)
	{
		while(dir = readdir(dp))
		{
			if((file = open(dir->d_name, O_RDONLY)) < 0) {fprintf(stderr, "\nError opening file."); exit(-1);}
			if(!(lseek(file, 0, SEEK_END))) {
				printf("\nDeleting %s.", dir->d_name);
				unlink(dir->d_name);
			}
		}
	}
}
