// Source:
// https://www.educative.io/courses/in-depth-understanding-of-memory-and-pointers-in-c/

#include <stdio.h>

int main() {
  int passwordOk = 0;
  char password[10];

  scanf("%s\n", password);
  // if password is longer than 10 characters, it will overwrite password0k in
  // memory

  if (passwordOk) {
    printf("Access granted\n");
    // do super important and super secret stuff here
  } else {
    printf("Access denied\n");
  }

  return 0;
}
