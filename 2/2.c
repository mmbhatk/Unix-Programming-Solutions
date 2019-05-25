#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>

int main()
{
	DIR* dp;
	struct dirent* dir;
	struct stat statfile;

	dp = opendir(".");

	if(dp)
	{
		while(dir = readdir(dp))
		{
			stat(dir->d_name, &statfile);
			printf("\n%s", dir->d_name);
			printf("\n%d %d %d %d %s\n", statfile.st_ino, statfile.st_size, statfile.st_uid, statfile.st_gid, ctime(&statfile.st_ctime));
		}
	}
}
