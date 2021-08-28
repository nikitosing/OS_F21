#include <stdio.h>

int main(int argc, char* argv[]){
	if (argc < 2) {
		printf("Put the command-line argument to specify the height of the triangle");
		return 0;
	}
	int n = 0;
	sscanf(argv[1], "%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (2 * n - 2 * i - 2) / 2; j++){
			putchar(' ');
		}
		for (int k = 0; k < (2 * i + 1); k++){
			putchar('*');
		}
		for (int j = 0; j < (2 * n - 2 * i - 2) / 2; j++){
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}