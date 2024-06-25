#include <atomic>
#include <mutex>
#include <thread>

#define NUM_THREADS 10
#define INCREMENTS_PER_THREAD 1000
#define DECREMENTS_PER_THREAD 900

class Counter {
 private:
  mutable std::mutex mtx;
  int value;

 public:
  Counter() : value(0) {}

  void increment() {
    std::lock_guard<std::mutex> lock(mtx);
    ++value;
  }

  void decrement() {
    std::lock_guard<std::mutex> lock(mtx);
    --value;
  }

  int get() const {
    std::lock_guard<std::mutex> lock(mtx);
    return value;
  }
};

class AtomicCounter {
 private:
  std::atomic<int> value;

 public:
  AtomicCounter() : value(0) {}

  void increment() { ++value; }
  void decrement() { --value; }
  int get() const { return value.load(); }
};

int main() {
  Counter counter;

  std::thread threads[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; ++i) {
    threads[i] = std::thread([&counter] {
      for (int i = 0; i < INCREMENTS_PER_THREAD; ++i) counter.increment();
      for (int i = 0; i < DECREMENTS_PER_THREAD; ++i) counter.decrement();
    });
  }

  for (int i = 0; i < 10; ++i) {
    threads[i].join();
  }

  printf("Counter value: %d\n", counter.get());

  AtomicCounter atomicCounter;

  for (int i = 0; i < NUM_THREADS; ++i) {
    threads[i] = std::thread([&atomicCounter] {
      for (int i = 0; i < INCREMENTS_PER_THREAD; ++i) atomicCounter.increment();
      for (int i = 0; i < DECREMENTS_PER_THREAD; ++i) atomicCounter.decrement();
    });
  }

  for (int i = 0; i < NUM_THREADS; ++i) {
    threads[i].join();
  }

  printf("AtomicCounter value: %d\n", atomicCounter.get());
}
