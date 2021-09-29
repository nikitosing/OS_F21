#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	
	printf("Input N: ");
	scanf("%d", &n);
	
	int * array = malloc(n * sizeof (int));
	for (int i = 0; i < n; i++) {
		array[i] = i;
		printf("array[%d] = %d\n", i, array[i]);
	}
	free(array)
}