#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    void* ptr;
    long to_allocate = 10 * 1024 * 1024;
    for (int i = 0; i < 20; ++i) {
        ptr = malloc(to_allocate);
        memset(ptr, 0, to_allocate);
        printf("%d MB allocated", (i+1)*10);
        sleep(1);
    }
    return 0;
}
