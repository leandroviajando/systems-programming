# Mastering Systems Programming: C, C++, and Rust

## Memory Management

- How does each language handle memory allocation and deallocation?

  - C: Manual memory allocation (usually with `malloc()`) and deallocation (with `free()`).
  - C++: RAII is implemented through constructors and destructors. The five special member functions (often called the "Rule of Five") are crucial for proper resource management.
  - Rust: Rust uses an ownership system with borrowing rules. The compiler tracks ownership and automatically inserts deallocation code when an object goes out of scope.

- What are the potential pitfalls in the C implementation?

  - Memory leaks (forgetting to free allocated memory)
  - Use-after-free errors (using memory after it's been deallocated)
  - Double free errors (trying to free memory that's already been freed)
  - Buffer overflows (writing beyond the allocated memory)

- How does C++'s RAII principle help prevent resource leaks?

  RAII ensures that resource acquisition (like memory allocation) occurs in the constructor and resource release (like memory deallocation) occurs in the destructor. This way, as long as objects are properly created and destroyed (which C++ guarantees for stack-allocated objects), resources will be properly managed. The copy and move operations ensure that resources are correctly handled when objects are copied or moved.

- Why doesn't the Rust implementation need a destructor?

  Rust's ownership system and borrowing rules allow the compiler to determine exactly when each piece of memory is no longer needed. At the end of a variable's lifetime (which the compiler tracks), Rust automatically inserts code to deallocate the memory. This is similar to a destructor, but it's handled by the language itself rather than requiring the programmer to write a destructor function.
