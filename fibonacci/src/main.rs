extern "C" {
    fn fib_recursive(n: u64) -> u64;
    fn fib_dp(n: u64) -> u64;
}

use std::io::{self, Write};
use std::time::{Duration, Instant};
enum FibonacciMethod {
    Recursive,
    DynamicProgramming,
}

fn measure_execution_time(method: FibonacciMethod, n: u64, repetitions: u32) -> Duration {
    let start = Instant::now();

    for _ in 0..repetitions {
        _ = match method {
            FibonacciMethod::Recursive => unsafe { fib_recursive(n) },
            FibonacciMethod::DynamicProgramming => unsafe { fib_dp(n) },
        }
    }

    let end = Instant::now();
    end - start
}

fn main() {
    println!(
        "This program calculates the running time of finding Fibonacci numbers \
               using two different algorithms: a recursive algorithm and an iterative \
               dynamic programming algorithm."
    );

    loop {
        print!("\nWhich Fibonacci number do you want to calculate: ");
        io::stdout().flush().unwrap();

        let mut n_input = String::new();
        io::stdin().read_line(&mut n_input).unwrap();
        let n: u64 = n_input.trim().parse().expect("Please enter a number");

        print!("\nHow many times do you want to perform the calculation? ");
        io::stdout().flush().unwrap();

        let mut times_input = String::new();
        io::stdin().read_line(&mut times_input).unwrap();
        let times: u32 = times_input.trim().parse().expect("\nPlease enter a number");

        let recursive_time = measure_execution_time(FibonacciMethod::Recursive, n, times);
        let dp_time = measure_execution_time(FibonacciMethod::DynamicProgramming, n, times);

        println!("\nRecursive Approach:");
        println!("Result: {}", unsafe { fib_recursive(n) });
        println!("Average Time: {:?}", recursive_time);

        println!("\nDynamic Programming Approach:");
        println!("Result: {}", unsafe { fib_dp(n) });
        println!("Average Time: {:?}", dp_time);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_fib_dp() {
        assert_eq!(unsafe { fib_dp(0) }, 0);
        assert_eq!(unsafe { fib_dp(1) }, 1);
        assert_eq!(unsafe { fib_dp(2) }, 1);
        assert_eq!(unsafe { fib_dp(5) }, 5);
        assert_eq!(unsafe { fib_dp(10) }, 55);
        assert_eq!(unsafe { fib_dp(20) }, 6765);
    }

    #[test]
    fn test_fib_recursive() {
        assert_eq!(unsafe { fib_recursive(0) }, 0);
        assert_eq!(unsafe { fib_recursive(1) }, 1);
        assert_eq!(unsafe { fib_recursive(2) }, 1);
        assert_eq!(unsafe { fib_recursive(5) }, 5);
        assert_eq!(unsafe { fib_recursive(10) }, 55);
        assert_eq!(unsafe { fib_recursive(20) }, 6765);
    }
}
