#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char input[1024];
	int res = 0;
    while (1) {
		printf("> ");
		scanf("%s", input);
		res = system(input);
    }
    return 0;
}

