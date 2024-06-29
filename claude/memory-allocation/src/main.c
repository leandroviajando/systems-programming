#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* data;
  size_t size;
  size_t capacity;
} Vector;

Vector* vector_create() {
  Vector* vec = (Vector*)malloc(sizeof(Vector));
  vec->capacity = 2;
  vec->data = (int*)malloc(sizeof(int) * vec->capacity);
  vec->size = 0;
  return vec;
}

void vector_push(Vector* vec, int value) {
  if (vec->size == vec->capacity) {
    vec->capacity *= 2;
    vec->data = (int*)realloc(vec->data, sizeof(int) * vec->capacity);
  }
  vec->data[vec->size++] = value;
}

void vector_free(Vector* vec) {
  free(vec->data);
  free(vec);
}

int main() {
  Vector* vec = vector_create();
  vector_push(vec, 1);
  vector_push(vec, 2);
  vector_push(vec, 3);
  for (size_t i = 0; i < vec->size; i++) printf("%d\n", vec->data[i]);
  vector_free(vec);
  return 0;
}
