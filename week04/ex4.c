#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_LENGTH 1024
int main() {
	char input[MAX_LENGTH];
	int res = 0;
    while (1) {
		printf("> ");
		fgets(input, MAX_LENGTH, stdin);
		res = system(input);
    }
    return 0;
}