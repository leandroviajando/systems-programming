#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../lib/fib/include/fib.h"

#define RECURSIVE 0
#define DYNAMIC_PROGRAMMING 1

typedef int FibonacciMethod;

unsigned long long int calculateFibonacci(FibonacciMethod method, int n) {
  if (method == RECURSIVE)
    return fib_recursive(n);
  else if (method == DYNAMIC_PROGRAMMING)
    return fib_dp(n);
  else {
    printf("Unknown method.\n");
    exit(EXIT_FAILURE);
  }
}

double measureExecutionTime(FibonacciMethod method, int n, int repetitions) {
  clock_t start = clock();
  for (int i = 0; i < repetitions; i++)
    calculateFibonacci(method, n);
  clock_t end = clock();

  double duration = ((double)(end - start)) / CLOCKS_PER_SEC;
  return duration / repetitions;
}

int main() {
  int n, times;

  printf("This program calculates the running time of finding Fibonacci numbers using two different algorithms: ");
  printf("a recursive algorithm and an iterative dynamic programming algorithm.\n");

  while (1) {
    printf("\nWhich Fibonacci number do you want to calculate: ");
    scanf("%d", &n);

    printf("\nHow many times do you want to perform the calculation (in order to find an average running time): ");
    scanf("%d", &times);

    double recursiveTime = measureExecutionTime(RECURSIVE, n, times);
    double dpTime = measureExecutionTime(DYNAMIC_PROGRAMMING, n, times);

    printf("\nRecursive Approach:\n");
    printf("Result: %llu\n", calculateFibonacci(RECURSIVE, n));
    printf("Average Time: %.6f seconds.\n", recursiveTime);

    printf("\nDynamic Programming Approach:\n");
    printf("Result: %llu\n", calculateFibonacci(DYNAMIC_PROGRAMMING, n));
    printf("Average Time: %.6f seconds.\n", dpTime);
  }

  return 0;
}
