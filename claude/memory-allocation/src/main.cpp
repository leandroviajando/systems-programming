#include <iostream>
#include <stdexcept>

class Vector {
 private:
  std::unique_ptr<int[]> data;
  size_t size;
  size_t capacity;

 public:
  Vector() : data(std::make_unique<int[]>(2)), size(0), capacity(2) {}

  void push(int value) {
    if (size == capacity) {
      capacity *= 2;
      auto new_data = std::make_unique<int[]>(capacity);
      std::copy(data.get(), data.get() + size, new_data.get());
      data = std::move(new_data);
    }
    data[size++] = value;
  }

  int& operator[](size_t index) {
    if (index >= size) throw std::out_of_range("Index out of range");
    return data[index];
  }

  size_t get_size() const { return size; }
};

int main() {
  Vector vec;
  vec.push(1);
  vec.push(2);
  vec.push(3);
  for (size_t i = 0; i < vec.get_size(); i++) std::cout << vec[i] << std::endl;
  return 0;
}
