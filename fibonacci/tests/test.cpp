#include <cassert>
#include <iostream>
#include <vector>

#include "../lib/fib/include/fib.h"

void test_fib_recursive() {
  assert(fib_recursive(0) == 0);
  assert(fib_recursive(1) == 1);
  assert(fib_recursive(5) == 5);
  assert(fib_recursive(10) == 55);
  assert(fib_recursive(15) == 610);
}

void test_fib_dp() {
  assert(fib_recursive(0) == 0);
  assert(fib_recursive(1) == 1);
  assert(fib_recursive(5) == 5);
  assert(fib_recursive(10) == 55);
  assert(fib_recursive(15) == 610);
}

int main() {
  test_fib_recursive();
  test_fib_dp();

  std::cout << std::endl
            << "All tests passed!" << std::endl
            << std::endl;
  return 0;
}
