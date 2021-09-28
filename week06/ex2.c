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

struct proccess * get_shortest_job(struct proccess* available_now[], int count){
	struct proccess * shortest_job = available_now[0];
	for (int i = 1; i < count; i++){
		if (available_now[i] -> burst_time < shortest_job -> burst_time) {
			shortest_job = available_now[i];
		}
	}
	return shortest_job;
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
		
		struct proccess * shortest_job = get_shortest_job(available_now, count);
		shortest_job->is_complete = 1;
		
		
		
		tat = wait_time + shortest_job->burst_time - shortest_job->arrival_time;
		if (tat < 0)
			tat = 0;
		wt = wait_time - shortest_job->arrival_time;
		if (wt < 0)
			wt = 0;
		
		printf("P#%d\t %d\t %d\t %d\t %d\t %d\n", 
			shortest_job->id, 
			shortest_job->arrival_time, 
			shortest_job->burst_time, 
			wait_time + shortest_job->burst_time, 
			tat,
			wt);
		wait_time += shortest_job->burst_time;
		now = shortest_job->arrival_time + shortest_job->burst_time;
	}
	
	return 0;
}