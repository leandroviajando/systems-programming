unsigned long long int fib_recursive(int n) {
  if (n <= 1)
    return n;

  return fib_recursive(n - 1) + fib_recursive(n - 2);
}

unsigned long long int fib_dp(int n) {
  unsigned long long int f[n + 1];
  f[0] = 0;
  f[1] = 1;

  for (int i = 2; i <= n; i++)
    f[i] = f[i - 1] + f[i - 2];

  return f[n];
}
