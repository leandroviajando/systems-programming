#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10
#define INCREMENTS_PER_THREAD 1000
#define DECREMENTS_PER_THREAD 900

typedef struct {
  int value;
  pthread_mutex_t mutex;
} Counter;

void counter_init(Counter* counter) {
  counter->value = 0;
  pthread_mutex_init(&counter->mutex, NULL);
}

void counter_increment(Counter* counter) {
  pthread_mutex_lock(&counter->mutex);
  counter->value++;
  pthread_mutex_unlock(&counter->mutex);
}

void counter_decrement(Counter* counter) {
  pthread_mutex_lock(&counter->mutex);
  counter->value--;
  pthread_mutex_unlock(&counter->mutex);
}

int counter_get(Counter* counter) {
  int result;
  pthread_mutex_lock(&counter->mutex);
  result = counter->value;
  pthread_mutex_unlock(&counter->mutex);
  return result;
}

void* thread_function(void* arg) {
  Counter* counter = (Counter*)arg;
  for (int i = 0; i < INCREMENTS_PER_THREAD; i++) counter_increment(counter);
  for (int i = 0; i < DECREMENTS_PER_THREAD; i++) counter_decrement(counter);
  return NULL;
}

int main() {
  Counter counter;
  counter_init(&counter);

  pthread_t threads[NUM_THREADS];

  for (int i = 0; i < NUM_THREADS; i++) {
    if (pthread_create(&threads[i], NULL, thread_function, &counter) != 0) {
      perror("Failed to create thread");
      return 1;
    }
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    if (pthread_join(threads[i], NULL) != 0) {
      perror("Failed to join thread");
      return 1;
    }
  }

  printf("Final count: %d\n", counter_get(&counter));

  return 0;
}
