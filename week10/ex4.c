#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>

int main(){
	DIR* dirp = opendir("tmp");
	if (dirp == NULL){ 
		return 0;
	}
	struct dirent* dp;
	while ((dp = readdir(dirp)) != NULL) {
		struct stat de_stat;
		char fname[] = "./tmp/";
		strcat(fname, dp->d_name);
		stat(fname, &de_stat);
		if (de_stat.st_nlink > 1) {
			printf("%lu %lu %s\n", dp->d_ino, de_stat.st_nlink, dp->d_name);
		}
	}
	(void) closedir(dirp);
	return 0;
}