#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void) {
	DIR* dir = opendir("/");
	if (dir == NULL){ 
		return 0;
	}
	
	struct dirent *ent = readdir(dir);
	while (ent != NULL) {
		printf ("%s\n", ent->d_name);
		ent = readdir(dir);
	}

	closedir(dir);
	return 0;
}