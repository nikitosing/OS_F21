#include <stdio.h>
#include <stdlib.h>

struct proccess{
	int arrival_time;
	int burst_time;
	int id;
	int is_complete;
	int wait_time;
	int remain_time;
	int was_proccessed_at_the_last_iteration;
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

int proccess_quantum_time(struct proccess* available_now[], int count, int quantum, int* wait_time){
	int sum = 0;
	for (int i = 0; i < count; i++){
		available_now[i] -> remain_time -= quantum;
		if (available_now[i] -> remain_time <= 0)
			available_now[i] -> is_complete = 1;
		int sub = quantum;
		if (available_now[i] -> remain_time < 0)
			sub += available_now[i] -> remain_time;
		available_now[i] -> wait_time = *wait_time - sub;
		*wait_time += sub;
		sum += sub;
	}
	return sum;
}

int count_uncomplete_proccesses(struct proccess array[], int size){
	int count = 0;
	for (int i = 0; i < size; i ++) {
		if (array[i].is_complete == 0) 
			count ++;
	}
	return count;
}


int main(){
	int n;
	int quantum;
	
	printf("Input a quantum: ");
	scanf("%d", &quantum);
	
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
		array[i].wait_time = 0;
		array[i].remain_time = array[i].burst_time;
		array[i].was_proccessed_at_the_last_iteration = 0;
	}
	
	bubble_sort_by_arrival_time(array, n);
	
	printf("P#\t AT\t BT\t CT\t TAT\t WT\n\n");
	int tat = 0;
	int wt = 0;
	int wait_time = 0;
	int now = 0;
	while (count_uncomplete_proccesses(array, n) > 0) {
		int count = 0;
		for(int j = 0; j < n; j++){
			if (array[j].arrival_time <= now && array[j].is_complete == 0)
				count ++;
		}
		
		struct proccess* available_now[count];
		count = 0;
		for(int j = 0; j < n; j++){
			if (array[j].arrival_time <= now && array[j].is_complete == 0){
				available_now[count] = &array[j];
				count ++;
			}
		}
		
		if (count == 0){
			now ++;
			continue;
		}
		
		now += proccess_quantum_time(available_now, count, quantum, &wait_time);
		
	}
	
	for (int i = 0; i < n; i++) {
		printf("P#%d\t %d\t %d\t %d\t %d\t %d\n", 
			array[i].id, 
			array[i].arrival_time, 
			array[i].burst_time, 
			array[i].burst_time + array[i].wait_time - array[i].arrival_time, 
			array[i].wait_time - array[i].arrival_time + array[i].burst_time,
			array[i].wait_time - array[i].arrival_time);
	}
	
	return 0;
}