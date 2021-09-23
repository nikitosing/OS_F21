#include <stdio.h>

struct proccess{
	unsigned int arrival_time;
	unsigned int burst_time;
};

void swap(struct proccess * a_, struct proccess * b_){
	struct proccess t = *a_;
	*a_ = *b_;
	*b_ = t;
}

void bubble_sort_by_arrival_time(struct proccess *array, int size){
	for (int i = 0; i < size - 1; i ++) {
		for (int j = i + 1; j < size; j ++) {
			if (array[j].arrival_time < array[i].arrival_time) {
				swap(&array[j], &array[i]);
			}
		}
	}		
}


int main(){
	unsigned int n;
	
	printf("Input number of a proccesses: ");
	scanf("%d", &n);
	
	struct proccess array[n];
	
	printf("Input elements of the array\n");
	for (int i = 1; i <= n; i++) {
		printf("Input arrival_time for [%u]: ", i);
		scanf("%d", &array[i].arrival_time);
		printf("Input burst_time for [%u]: ", i);
		scanf("%d", &array[i].burst_time);
	}
	
	bubble_sort_by_arrival_time(array, n);
	
	printf("P#\t AT\t BT\t CT\t TAT\t WT\n\n");
	
	unsigned int wait_time = 0;
	for (int i = 1; i <= n; i++) {
		printf("P#%d\t %u\t %u\t %u\t %u\t %u\n", 
			i, 
			array[i].arrival_time, 
			array[i].burst_time, 
			wait_time + array[i].burst_time, 
			wait_time + array[i].burst_time - array[i].arrival_time,
			wait_time - array[i].arrival_time);
		wait_time += array[i].burst_time;
	}
	
	return 0;
}