#include <stdio.h>


int main(){
	dirp = opendir("tmp");
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