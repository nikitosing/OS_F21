#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>

int main(){
	DIR	= opendir("tmp");
	if (dirp == NULL){ 
		return 0;
	}
	len = strlen(name);
	while (( dp = readdir(dirp)) != NULL ) {
		if (dp->st_nlink > 1) {
			printf("%d %d %s", dp->st_ino, dp->st_nlink, dp->d_name);
		}
	}
	(void) closedir(dirp);
	return 0;
}