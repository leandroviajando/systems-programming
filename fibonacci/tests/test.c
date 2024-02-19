#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../lib/fib/include/fib.h"

void test_fib_recursive() {
  assert(fib_recursive(0) == 0);
  assert(fib_recursive(1) == 1);
  assert(fib_recursive(5) == 5);
  assert(fib_recursive(10) == 55);
  assert(fib_recursive(15) == 610);
}

void test_fib_dp() {
  assert(fib_dp(0) == 0);
  assert(fib_dp(1) == 1);
  assert(fib_dp(5) == 5);
  assert(fib_dp(10) == 55);
  assert(fib_dp(15) == 610);
}

int main() {
  test_fib_recursive();
  test_fib_dp();

  printf("\nAll tests passed!\n\n");
  return 0;
}
