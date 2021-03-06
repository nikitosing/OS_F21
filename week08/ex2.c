#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
The only thing was changed during the execution time is a free memory in `vmstat` info. `si` and `so` are 0.
*/

/*
If we are looking at the output of `top`. We can see, that VIRT and RES for our proccess grow as fast as program alocating new memory
*/

int main() {
    void* ptr;
    long to_allocate = 10 * 1024 * 1024;
    for (int i = 0; i < 100; ++i) {
        ptr = malloc(to_allocate);
        memset(ptr, 0, to_allocate);
        printf("%d MB allocated\n", (i+1)*10);
        sleep(1);
    }
    return 0;
}
