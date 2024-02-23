#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("a char is %ld bytes\n", sizeof(char));                // 1
  printf("a short int is %ld bytes\n", sizeof(short int));      // 2
  printf("an int is %ld bytes\n", sizeof(int));                 // 4
  printf("a long int is %ld bytes\n", sizeof(long int));        // 8
  printf("a float is %ld bytes\n", sizeof(float));              // 4
  printf("a double is %ld bytes\n", sizeof(double));            // 8
  printf("a long double is %ld bytes\n", sizeof(long double));  // 16
  return 0;
}
