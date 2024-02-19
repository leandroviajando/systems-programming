#include <iostream>

/*
 * isStackGrowingUpwards recursively checks the stack growth direction.
 *
 * Returns 1 if the stack grows upwards, 0 if downwards.
 */
bool isStackGrowingUpwards(int* previous) {
  int current;

  return !previous ? isStackGrowingUpwards(&current) : &current > previous;
}

int main() {
  std::cout << "This is a C++ script checking stack growth direction:" << std::endl;
  std::cout << (isStackGrowingUpwards(nullptr) ? "Up" : "Down") << std::endl;
  return 0;
}
