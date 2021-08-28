#include <stdio.h>
#define FIGURE_WIDTH 10

void print_default_pyramid(int n){
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
}

void print_square(int height){
	for (int i = 1; i <= height; i ++){
		for (int j = 0; j < FIGURE_WIDTH; j ++){
			putchar('*');
		}
		putchar('\n');
	}
}

void print_right_triangle(int height){
	for (int i = 1; i <= height; i ++){
		for (int j = 0; j < i; j ++){
			putchar('*');
		}
		putchar('\n');
	}
}

void print_rotated_pyramid(int height){
	for (int i = 1; i <= height / 2; i ++){
		for (int j = 0; j < i; j ++){
			putchar('*');
		}
		putchar('\n');
	}
	for (int i = height / 2 + height % 2; i > 0; i--){
		for (int j = 0; j < i; j ++){
			putchar('*');
		}
		putchar('\n');
	}
}

int main(int argc, char* argv[]){
	if (argc < 3) {
		printf("Put the command-line argument to specify the type of the figure and its height:\n	1 - pyramid;\n	2 - square with the width %d;\n	3 - rigth triangle;\n	4 - rotated pyramid", FIGURE_WIDTH);
		return 0;
	}
	
	int height = 0;
	int type = 0;
	
	sscanf(argv[1], "%d", &type);
	sscanf(argv[2], "%d", &height);
	
	switch (type){
		case 1: 
			print_default_pyramid(height);
			break;
		case 2:
			print_square(height);
			break;
		case 3: 
			print_right_triangle(height);
			break;
		case 4:
			print_rotated_pyramid(height);
			break;
	}
	return 0;
}