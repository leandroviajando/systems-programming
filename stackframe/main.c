// Source: https://youtu.be/V2h_hJ5MSpY

#include <stdio.h>

/*
 * isStackGrowingUpwards recursively checks the stack growth direction.
 *
 * Returns 1 if the stack grows upwards, 0 if downwards.
 */
int isStackGrowingUpwards(int *previous) {
  int current;

  return !previous ? isStackGrowingUpwards(&current) : &current > previous;
}

int main() {
  printf("This is a C script checking stack growth direction:\n");
  printf("%s\n", isStackGrowingUpwards(NULL) ? "Up" : "Down");
  return 0;
}
