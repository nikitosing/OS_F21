#include <stdio.h>
#include <string.h>

int main(){
	char* input;
	
	printf("Input a string: \n");
	scanf("%s", input);
	
	for (int i = strlen(input) - 1; i >= 0; i--) {
        putchar(input[i]);
    }
	return 0;
}