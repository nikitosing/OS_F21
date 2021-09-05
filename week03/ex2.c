#include <stdio.h>

void swap(int * a_, int * b_){
	int t = *a_;
	*a_ = *b_;
	*b_ = t;
}

void bubble_sort(int *array, int size){
	for (int i = 0; i < size - 1; i ++) {
		for (int j = i + 1; j < size; j ++) {
			if (array[j] < array[i]) {
				swap(&array[j], &array[i]);
			}
		}
	}		
}

int main(){
	int size;
	
	printf("Input a size of an array\n");
	scanf("%d", &size);
	
	int array[size];
	
	printf("Input elements of the array\n");
	for (int i = 0; i < size; i++) {
		scanf("%d", &array[i]);
	}
	
	bubble_sort(array, size);
	
	printf("Sorted array:");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	
	return 0;
}