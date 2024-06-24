#include <cstring>
#include <iostream>
#include <utility>

class String {
 private:
  char* data;
  size_t length;

  // RAII (Resource Acquisition Is Initialization) is a C++ programming
  // technique where resource management is tied to object lifetime.
  // Rule of Five: Constructor, Destructor, Copy constructor, Copy
  // assignment operator, Move constructor, Move assignment operator

 public:
  // Constructor
  String(const char* str) : length(std::strlen(str)) {
    data = new char[length + 1];
    std::strcpy(data, str);
  }

  // Destructor
  ~String() { delete[] data; }

  // Copy constructor
  String(const String& other) : length(other.length) {
    data = new char[length + 1];
    std::strcpy(data, other.data);
  }

  // Copy assignment operator: creates a temporary copy and swaps it with the
  // current object
  String& operator=(const String& other) {
    if (this != &other) {
      String tmp(other);
      std::swap(*this, tmp);
    }
    return *this;
  }

  // Move constructor: "steals" resources from the other object, leaving it in a
  // valid but empty state
  String(String&& other) noexcept : data(other.data), length(other.length) {
    other.data = nullptr;
    other.length = 0;
  }

  // Move assignment operator
  String& operator=(String&& other) noexcept {
    std::swap(data, other.data);
    std::swap(length, other.length);
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const String& str) {
    return os << str.data;
  }
};

int main() {
  String string("Hello, World!");
  std::cout << string << std::endl;  // Hello, World!
  return 0;
}
