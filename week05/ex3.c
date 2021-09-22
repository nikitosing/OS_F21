#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_cond_t FULL, EMPTY;
int count = 0;

void *producerFunction() {
  while (1) {
    if (count == 1024) {
      printf("count == 1024, go to sleep [producer]\n");
      sleep(1);
    }
    count++;
    printf("count == %d [producer]\n", count);
    if (count == 1) {
      printf("count = 1 [producer]\n");
      pthread_cond_signal(&FULL);
    }
  }
}

void *consumerFunction() {
  while (1) {
    if (count == 0) {
      printf("count == 0\n");
      sleep(1);
    }
    count--;
    printf("count == %d [consumer]\n", count);
    if (count == 1024 - 1) {
      printf("There are some space in buffer\n");
      pthread_cond_signal(&EMPTY);
    }
  }
}

void main() {
  pthread_t threadProducer, threadConsumer;

  pthread_cond_init(&FULL, 0);
  pthread_cond_init(&EMPTY, 0);

  pthread_create(&threadProducer, NULL, producerFunction, NULL);
  pthread_create(&threadConsumer, NULL, consumerFunction, NULL);

  pthread_join(threadProducer, 0);
  pthread_join(threadConsumer, 0);
}