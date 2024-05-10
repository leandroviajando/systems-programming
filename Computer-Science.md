# Computer Science

## [Information Representation (3h)](https://www.educative.io/courses/information-representation-computer-systems)

Writing to a file: `>` (overwrite) or `>>` (append)

Redirect standard error `2>` to a file: `command 2> error.txt`
Redirect standard output `>` and standard error `2>` to a file: `command > output.txt 2> error.txt`
Redirect standard error to standard output: `command 2>&1`

### [Bit Manipulation (3h)](https://www.educative.io/courses/bit-manipulation)

1. **Bitwise Conjunction (`&`) - AND Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100
       int b = 25;     // Binary: 11001

       int result = a & b;   // 1100 & 11001 = 1000 (8 in decimal)

       printf("Result of bitwise AND: %d\n", result); // Output: 8

       return 0;
   }

   ```

2. **Bitwise Disjunction (`|`) - OR Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100
       int b = 25;     // Binary: 11001

       int result = a | b;   // 1100 | 11001 = 11101 (29 in decimal)

       printf("Result of bitwise OR: %d\n", result); // Output: 29

       return 0;
   }

   ```

3. **Bitwise Exclusive OR (`^`) - XOR Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100
       int b = 25;     // Binary: 11001

       int result = a ^ b;   // 1100 ^ 11001 = 10101 (21 in decimal)

       printf("Result of bitwise XOR: %d\n", result); // Output: 21

       return 0;
   }

   ```

4. **Bitwise Negation (`~`) - NOT Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100

       int result = ~a;   // ~1100 = 0011 (-13 in decimal)

       printf("Result of bitwise NOT: %d\n", result); // Output: -13

       return 0;
   }

   ```

5. **XOR Logic Gate inverts the AND Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100
       int b = 25;     // Binary: 11001

       int result_and = a & b;   // 1100 & 11001 = 1000 (8 in decimal)
       int result_xor = ~result_and; // Inverting the AND result

       printf("Result of inverted AND (XOR): %d\n", result_xor); // Output: -9

       return 0;
   }

   ```

6. **NOR Logic Gate inverts the OR Logic Gate**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100
       int b = 25;     // Binary: 11001

       int result_or = a | b;   // 1100 | 11001 = 11101 (29 in decimal)
       int result_nor = ~result_or; // Inverting the OR result

       printf("Result of inverted OR (NOR): %d\n", result_nor); // Output: -30

       return 0;
   }

   ```

7. **Bitwise Left-Shift (`<<`) - Doubling Signed Integers**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100

       a <<= 1;   // Left shift a by 1 bit: 11000 (24 in decimal)

       printf("Result of left shift: %d\n", a); // Output: 24

       return 0;
   }

   ```

8. **Bitwise Right-Shift (`>>`) - Halving Signed Integers**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100

       a >>= 1;   // Right shift a by 1 bit: 110 (6 in decimal)

       printf("Result of right shift: %d\n", a); // Output: 6

       return 0;
   }

   ```

9. **Bitwise Assignment Operators (`&=`, `|=`, `^=`, `<<=`, `>>=`)**

   ```c
   #include <stdio.h>

   int main() {
       int a = 12;     // Binary: 1100

       a <<= 2;   // Left shift a by 2 bits: 110000 (48 in decimal)

       printf("Result of left shift: %d\n", a); // Output: 48

       return 0;
   }

   ```

### [Number Systems (2h)](https://www.educative.io/courses/number-systems-for-computer-scientists)

## [Theory of Computation (15h)](https://www.educative.io/courses/theory-of-computation)

### Languages

### Grammars

### Finite-State Machines

### Automata

### Propositional Logic

### First-Order Logic

### P and NP

## [Memory and Pointers in C (20h)](https://www.educative.io/courses/in-depth-understanding-of-memory-and-pointers-in-c)

- [ ] Pointers, malloc(), calloc(), realloc(), free(), dangling pointers, memory leaks, stack vs. heap.
- [ ] CPU components (registers, ALU, control unit).
- [ ] Memory hierarchy (cache, RAM, etc.).
- [ ] Concept of instruction sets.
- [ ] Processors, combinational and sequential logic
- [ ] Smart Pointers and RAII: Understand unique_ptr, shared_ptr, weak_ptr, and the importance of RAII in C++.
- [ ] HTTP server in C/C++
  - [ ] Learn to code defensively when interacting with the web, the OS, memory.
- [ ] Learn to use GDB (or LLDB). Practice on your projects:
  - [ ] Setting breakpoints
  - [ ] Inspecting memory and variables
  - [ ] Stepping through code
- [ ] Explore memory profiling tools like Valgrind.

## [Operating Systems (40h)](https://www.educative.io/courses/operating-systems-virtualization-concurrency-persistence)

[Writing an OS in Rust](https://os.phil-opp.com/)

### The OS Kernel

### Process Management: Processes, Threads, and Inter-Process Communication

### Time Management: CPU Scheduling Algorithms

### Resource Management

#### Synchronisation

#### Mutual Exclusion

#### Semaphores

#### Deadlock Prevention

#### Deadlock Avoidance and Detection

### Memory Management

#### Allocation, Protection, and Sharing of Memory

#### Physical and Virtual Memory

#### Paged Virtual Memory

### Storage Management

#### Storage Technologies

#### File Systems

### Virtualisation

#### Virtual Machines

#### Containers

## [Computer Networking (20h)](https://www.educative.io/courses/grokking-computer-networking)

## [Computer Security (9h)](https://www.educative.io/courses/practical-security-defending-your-systems)

## [Databases (19h)](https://www.educative.io/courses/deep-dive-into-the-internals-of-the-database)

[Competitive Programming in C++: The Keys to Success (5h)](https://www.educative.io/courses/competitive-programming-in-cpp-keys-to-success)

[Linear Algebra for Data Science Using Python (10h)](https://www.educative.io/courses/linear-algebra-for-data-science-using-python)
