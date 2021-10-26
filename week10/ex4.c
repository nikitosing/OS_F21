#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/dir.h>
#define N 1024

struct node_group{
	int id;
	char *names;
};

int main(){
	struct node_group file_groups[N];
	
	DIR* dirp = opendir("tmp");
	if (dirp == NULL){ 
		return 0;
	}
	int count = 0;
	struct dirent* dp;
	while ((dp = readdir(dirp)) != NULL) {
		struct stat de_stat;
		char fname[] = "./tmp/";
		strcat(fname, dp->d_name);
		stat(fname, &de_stat);
		if (de_stat.st_nlink > 1) {
			int flag = 0;
			for (int i = 0; i < count; i++){
				if (file_groups[i].id == dp->d_ino) {
					flag = 1;
					strcat(file_groups[i].names, dp->d_name);
				}
				if (!flag){
					file_groups[count].id = dp->d_ino;
					file_groups[count].names = strdup(dp->d_name)
					strcat(file_groups[count].names, " - ");
					count ++;
				}
			}
			printf("%lu %lu %s\n", dp->d_ino, de_stat.st_nlink, dp->d_name);
		}
	}
	for (int i = 0; i < count; i++){
		printf("%s\n", file_groups[count].names);
	}		
	(void) closedir(dirp);
	return 0;
}