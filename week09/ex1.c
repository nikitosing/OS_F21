#include <stdio.h>

#define N 100 // page frames

struct page {
	int id;
	int age;
	int r;
};
	
#define pages_at_tick N // the same as N


int find_page(struct page * arr, int page_to_find){
	for (int i = 0; i < N; i ++) {
		if (arr[i].id == page_to_find) {
			arr[i].r = 1;
			return 1;
		}
	}
	return 0;
}


int find_most_unused_page(struct page * arr, int requested_page){
	int lowest_age = 1024; 
	for (int i = 0; i < N; i ++) {
		if (arr[i].age < lowest_age) {
			lowest_age = arr[i].age;
		}
	}
	for (int i = 0; i < N; i ++) {
		if (arr[i].age == lowest_age) {
			int flag = arr[i].id == 0;
			arr[i].age = 0;
			arr[i].r = 1;
			arr[i].id = requested_page;
			return flag;
		}
	}
	return 0;
}

int main() {
	struct page memory[N];
	for (int i = 0; i < N; i++){
		memory[i].id = 0;
		memory[i].age = 0;
		memory[i].r = 0;
	}
	
    FILE *fin = fopen("input.txt", "r");
	
	float hits = 0;
	float misses = 0;
	int pages_taken_in_one_tick = 0;
	while (! feof(fin)){
		if (pages_taken_in_one_tick == 0){
			for (int i = 0; i < N; i++){
				memory[i].r = 0;
			}
		}
		int requested_page;
		fscanf(fin, "%d", &requested_page);
		
		int is_fetched = find_page(memory, requested_page);
		if (is_fetched){
			hits += 1;
			
		} else{
			misses += 1;
			find_most_unused_page(memory, requested_page);
		}
		
		
		pages_taken_in_one_tick = (pages_taken_in_one_tick + 1) % pages_at_tick;
		if (pages_taken_in_one_tick == 0){
			for (int i = 0; i < N; i++){
				memory[i].age >>= 1;
				memory[i].age |= memory[i].r << (8-1);
			}
		}
	}
	float ratio = hits/misses;
	
	printf("hits = %.0f, misses = %.0f, ratio = %.10f", hits, misses, ratio);
}	
