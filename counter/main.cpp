// Source: https://www.educative.io/courses/learn-cpp-from-scratch

namespace counter {

#include <iostream>

template <class T>
class Score {
 private:
  T value;

 public:
  static int counter;
  Score() { counter++; }
};

template <class T>
int Score<T>::counter = 0;

int main() {
  Score<int> x;
  Score<int> y;
  Score<double> z;

  std::cout << Score<int>::counter << std::endl;
  std::cout << Score<double>::counter << std::endl;

  return 0;
}
// Output:
// 2
// 1

}  // namespace counter
