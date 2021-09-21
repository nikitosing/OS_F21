#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>

void* threadFunction() {
	printf("Hello from the thread #%d\n", pthread_self());
	return 0;
}

int main() {
	int N = 5;
	
	pthread_t threads[N];
	
	for(int i = 0; i < N; ++i) {
		if(pthread_create(&threads[i], NULL, threadFunction, NULL) == 0) {
			printf("Thread #%d has been created\n", threads[i]);
		}
		pthread_join(threads[i], NULL);
	}
	return 0;
}