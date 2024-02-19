// Source: https://github.com/christopher-siewert/fibonacci-time-analysis

#include <chrono>
#include <iostream>

#include "../lib/fib/include/fib.h"

enum class FibonacciMethod { Recursive,
                             DynamicProgramming };

unsigned long long int calculateFibonacci(FibonacciMethod method, int n) {
  switch (method) {
    case FibonacciMethod::Recursive:
      return fib_recursive(n);
    case FibonacciMethod::DynamicProgramming:
      return fib_dp(n);
    default:
      std::cout << "Unknown method." << std::endl;
  }
}

double measureExecutionTime(FibonacciMethod method, int n, int repetitions) {
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < repetitions; i++)
    calculateFibonacci(method, n);
  auto end = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

  return static_cast<double>(duration) / repetitions;
}

int main() {
  int n, times;

  std::cout << "This program calculates the running time of finding Fibonacci numbers using two different algorithms: "
            << "a recursive algorithm and an iterative dynamic programming algorithm." << std::endl;

  while (true) {
    std::cout << std::endl
              << "Which Fibonacci number do you want to calculate: ";
    std::cin >> n;

    std::cout << std::endl
              << "How many times do you want to perform the calculation (in order to find an average running time): ";
    std::cin >> times;

    auto recursiveTime = measureExecutionTime(FibonacciMethod::Recursive, n, times);
    auto dpTime = measureExecutionTime(FibonacciMethod::DynamicProgramming, n, times);

    std::cout << std::endl
              << "Recursive Approach:" << std::endl
              << "Result: " << calculateFibonacci(FibonacciMethod::Recursive, n) << std::endl
              << "Average Time: " << recursiveTime << " microseconds." << std::endl;

    std::cout << std::endl
              << "Dynamic Programming Approach:" << std::endl
              << "Result: " << calculateFibonacci(FibonacciMethod::DynamicProgramming, n) << std::endl
              << "Average Time: " << dpTime << " microseconds." << std::endl;
  }

  return 0;
}
