#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

int _main(){
	pid_t pid_forked = fork();
	for (int i = 0; i < 3; i++){
		fork();
		sleep(5);
	}
	
	return 0;
}

int main(){
	pid_t pid_forked = fork();
	for (int i = 0; i < 5; i++){
		fork();
		sleep(5);
	}
	
	return 0;
}