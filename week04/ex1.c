#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	int n = 1;
	pid_t pid_forked = fork();
	if (pid_forked == 0){
		for (int i = 0; i < 10; i++){
			printf("Hello from child [%d - %d]\n", getpid(), i);
		}
	} else if (pid_forked > 0){
		for (int i = 0; i < 10; i++){
			printf("Hello from parent [%d - %d]\n", getpid(), i);
		}
	} else {
		printf("Some error\n");
	}
	return 0;
}