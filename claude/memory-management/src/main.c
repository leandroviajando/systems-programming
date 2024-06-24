#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* data;
  size_t length;
} String;

String* string_create(const char* str) {
  String* string = malloc(sizeof(String));

  string->length = strlen(str);
  string->data = malloc(string->length);
  strcpy(string->data, str);

  return string;
}

void string_destroy(String* string) {
  free(string->data);
  free(string);
}

int main() {
  String* string = string_create("Hello, World!");
  printf("%s\n", string->data);  // Hello, World!
  string_destroy(string);
  return 0;
}
