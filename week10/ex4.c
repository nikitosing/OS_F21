#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>

int main(){
	DIR* dirp = opendir("tmp");
	if (dirp == NULL){ 
		return 0;
	}
	struct dirent* dp;
	while ((dp = readdir(dirp)) != NULL ) {
		struct stat de_stat;
		stat(dp->d_name, &de_stat);
		if (de_stat.st_nlink > 1) {
			printf("%d %d %s", dp->d_ino, de_stat.st_nlink, dp->d_name);
		}
	}
	(void) closedir(dirp);
	return 0;
}