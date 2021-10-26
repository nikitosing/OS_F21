#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>


int main() {
    void* ptr;
	struct rusage usage;
    long to_allocate = 10 * 1024 * 1024;
	getrusage(RUSAGE_SELF, &usage);
	printf("%ld used\n", usage.ru_maxrss);
    for (int i = 0; i < 10; ++i) {
        ptr = malloc(to_allocate);
        memset(ptr, 0, to_allocate);
        printf("%d MB allocated\n", (i+1)*10);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld used\n", usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}
