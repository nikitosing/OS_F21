#include <stdio.h>
#include <stdlib.h>

struct proccess{
	int arrival_time;
	int burst_time;
	int id;
	int is_complete;
};

void swap(struct proccess* arr, int a, int b){
	struct proccess t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}

void bubble_sort_by_arrival_time(struct proccess *array, int size){
	for (int i = 0; i < size - 1; i ++) {
		for (int j = i + 1; j < size; j ++) {
			if (array[j].arrival_time < array[i].arrival_time) {
				swap(array, i, j);
			}
		}
	}		
}


int main(){
	int n;
	
	printf("Input number of a proccesses: ");
	scanf("%d", &n);
	
	struct proccess array[n];
	
	printf("Input elements of the array\n");
	for (int i = 0; i < n; i++) {
		printf("Input arrival_time for [%d]: ", i);
		scanf("%d", &array[i].arrival_time);
		printf("Input burst_time for [%d]: ", i);
		scanf("%d", &array[i].burst_time);
		array[i].id = i + 1;
		array[i].is_complete = 0;
	}
	
	bubble_sort_by_arrival_time(array, n);
	
	printf("P#\t AT\t BT\t CT\t TAT\t WT\n\n");
	int tat = 0;
	int wt = 0;
	int wait_time = 0;
	for (int i = 0; i < n; i++) {
		tat = wait_time + array[i].burst_time - array[i].arrival_time;
		if (tat < 0)
			tat = 0;
		wt = wait_time - array[i].arrival_time;
		if (wt < 0)
			wt = 0;
		printf("P#%d\t %d\t %d\t %d\t %d\t %d\n", 
			array[i].id, 
			array[i].arrival_time, 
			array[i].burst_time, 
			wait_time + array[i].burst_time, 
			tat,
			wt);
		wait_time += array[i].burst_time;
	}
	
	return 0;
}