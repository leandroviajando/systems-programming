# Classes in C++

## Class Constructors

The automatic default constructor will only initialize all member variables to their default values.

## Copy Constructors

A copy constructor takes one argument, a reference to an object of the same type, which is copied to create a new instance of the same type.

The automatic copy constructor will copy the contents of all member variables.

## Copy Assignment Operator

While a copy constructor always creates a new object (it is a constructor), an assignment operator assigns a value to an existing object (it is always called on an object that has already been constructed).

The automatic assignment operator will copy the contents of all member variables.

```c++
#include "Cube.h"
#include <iostream>

namespace uiuc {
  Cube::Cube() {
    length_ = 1;
    std::cout << "Default constructor invoked!" << std::endl;
  }

  Cube::Cube(const Cube & obj) {
    length_ = obj.length_;
    std::cout << "Copy constructor invoked!" << std::endl;
  }

  Cube & Cube::operator=(const Cube & obj) {
    length_ = obj.length_;
    std::cout << "Assignment operator invoked!" << std::endl;
    return *this;
  }
}
```

## Variable Storage / Pass / Return

- by pointer `*`
- by reference `&` / acts as an alias
- by value / copy

Never return a reference to a stack variable created on the stack of a function!

## Class Destructor

A destructor is called

- when the function returns, if the object is on the stack
- when delete is used, if the object is on the heap

```c++
  Cube::~Cube() {
    cout << "Destroyed $" << getVolume() << endl;
  }
```

The default destructor calls the destructors of all member variables.

A custom destructor is essential when an object allocates an external resource that must be closed or freed when the object is destroyed! Examples:

- Heap memory
- Open files
- Shared memory

## C++ Syntax Notes: Uninitialized Pointers, Segfaults, and Undefined Behaviour

### Segmentation Fault (Segfault)

On Linux, if you dereference an address that you shouldn't, this is often called "segmentation fault," or "segfault." For example, if you dereference a pointer that is set to `nullptr`, it will almost certainly cause a segfault and crash immediately.

This code compiles successfully, runs, and crashes with a segfault:

```c++
int* n = nullptr;
std::cout << *n << std::endl;
```

Segfaults are an example of undefined behaviour.

### Undefined Behaviour

There are some improper ways to write C++ that are not strictly forbidden by the C++ standard, but the C++ standard doesn't define how compilers are supposed to handle those situations, so your compiler may generate a program that works, or not! This is called "undefined behavior" - a programme that compiles, but that is not really a safe or valid programme.

Often times, undefined behaviour is caused by the careless use of uninitialized variables.

### Initialization

Initialization is specifying a value for a variable from the moment it is created.

If you dereference an uninitialized pointer, even just to read from it and not to write to it, you may cause your program to crash, or something else unexpected might happen later.

#### Examples with Stack Memory

This pointer `x` is uninitialized. It contains a seemingly random memory address. (However, this is also not a good way to get a source of randomness, even for those situations where we want random numbers!) Dereferencing this pointer would cause undefined (unpredictable) behavior:

```c++
// Bad:
int *x;
```

This pointer is explicitly initialized to `nullptr`. Dereferencing this pointer would cause the program to crash, immediately and predictably. (On Linux, this is often called a "segmentation fault," or "segfault.") As we'll discuss below, it's a good practice to set a pointer to `nullptr` if you aren't setting it to any other value immediately:

```c++
// Good:
int *y = nullptr;

// Alternative way to initialize:
int* y2(nullptr);

// Better b/c can't be confused with a function call (since C++11):
int* y3{nullptr};
```

Here we create integer `i` on the stack, safely initialized with value `7`, and then we create a pointer `z` on the stack, initialized to the address of `i`. This way, `z` points to `i`. It's safe to dereference `z`:

```c++
int i = 7;
int *z = &i;
```

#### Examples with Heap Memory

**As with stack memory, you should be wary when you use "`new`" for a built-in type like `int`, since these types may not have default initialization. Therefore, you shouldn't assume they'll have an expected default value (such as `0`). For those cases, be sure to initialize the value manually.**

The pointer `q` is created and initialized with the address for a newly-allocated integer on the heap. However, the integer that `q` points to does not have a predictable value. It depends on the compiler. We shouldn't rely on this integer to have any particular value at the beginning:

```c++
int *q = new int;
```

You can specify initialization parameters at the end of the "`new`" expression. This will create pointer `r` initialized with newly-allocated memory for an integer with the value `0` explicitly:

```c++
int *r = new int(0);
```

**There are a lot of special situations in C++ where different factors may slightly change how an object is initialized. If you're unsure, the easiest thing to do is make sure that you explicitly initialize your variables. For a more exhaustive reference on initialization, you can refer to this page: <https://en.cppreference.com/w/cpp/language/initialization>**

### Resetting deleted pointers to `nullptr`

Note that using `delete` on a pointer frees the heap memory allocated at that address. However, deleting the pointer does not change the pointer value itself to `nullptr` automatically; you should do that yourself after using "`delete`", as a safety precaution. For example:

```c++
// Allocate an integer on the heap:
int* x = new int;

// Now x holds some memory address to a valid integer.
// Do some kind of work with the integer.
// We'll just set that integer to 7:
*x = 7;

// Now delete the pointer to deallocate the heap memory:
delete x;

// This destroys the integer on the heap and frees the memory.
// But now x still holds the memory address!
// Set x to nullptr for safety:
x = nullptr;
```

By manually setting `x` to `nullptr` after "`delete x`", we help prevent two kinds of problems:

1. We don't want to delete the same allocated address more than once by mistake, which could cause *errors*. Using "`delete`" on `nullptr` does nothing, so this way, if we accidentally try to delete the same address twice, nothing further happens.

2. We must never dereference a pointer to deallocated memory. This could cause the program to crash with a segfault, exhibit strange behavior, or cause a security vulnerability. However, *attempting to dereference a nullptr will almost always cause a segfault and terminate the program immediately. This is actually better than causing a silent security vulnerabilty* or another problem that is harder to detect! Therefore, it makes sense to set the deleted pointer to `nullptr`, thus ensuring that if we dereference it carelessly, then it will cause a very obvious runtime error that we can fix.

You should also note that we only need to use `delete` and `nullptr` with pointers, of course. Variables in stack memory don't need to be manually deleted. Those are automatically deallocated when they go out of scope.

**In summary, remember that if you use `new`, you will also need to `delete`, and after you delete, you should set to `nullptr`.**

### Beyond Pointers

Class types can be designed handle all the `new` and `delete` operations for you, invisibly. As you create your own robust data structures, and as you use libraries such as the C++ Standard Template Library, you will find that you very rarely have to use `new` and `delete` anymore.

## C++ Syntax Notes: The Modern Range-Based "for" Loop

In recent versions of C++, there is a version of the `for` loop that automatically iterates over all of the things in a container.

**This is very useful when used with a standard library container, because you don't have to worry about trying to access memory outside of a safe range.**

1. If you declare an ordinary temporary variable in the loop, it just gets a copy of the current loop item by value. Changes you make to that temporary copy won't affect the actual container!

    ```c++
      for (int x : int_list) {
        std::cout << "This item has value: " << x << std::endl;
      }
    ```

2. If you make the temporary variable of a reference type, you can actually modify the current container item instead of just getting a copy.

    ```c++
      for (int& x : int_list) {
        // This version of the loop will modify each item directly, by reference!
        x = 99;
      }
    ```

3. If you are iterating over large objects in a container, then even if you don't want to modify the objects, you might want to use a reference to a constant as the loop variable type to avoid making a temporary copy of a large object, which could otherwise be slow.

    ```c++
      for (const int& x : int_list) {
        // This version uses references, so it doesn't make any temporary copies.
        // However, they are read-only, because they are marked const!
        std::cout << "This item has value: " << x << std::endl;
        // This line would cause an error:
        //x = 99;
      }
    ```

## Unsigned Integer Types: Be Careful

Unsigned integers are sometimes used in special cases to make use of memory extremely efficiently; for example, a data storage format might use them in order to be more compact.

```c++
int a = 7;
// signed int a = 7;
unsigned int b = 8;
```

But mixing unsigned and signed integers in your code can cause unexpected problems.

### Issues with unsigned arithmetic

Unsigned ints can't represent negative values. Instead, they sacrifice the ability to represent negative numbers in exchange for a higher upper positive limit to the value range that they can represent, using the same number of bits as the comparable signed integer. However, the underlying bit representation that unsigned integers use for these very large values is actually the same as the representation that signed integers use for their negative value range.

You do need to be careful if you are approaching the upper limit for a signed int even if you are using unsigned ints. Signed ints have a lower maximum value, so if you get an unsigned int greater than that limit and then cast it to signed int, it will be interpreted as a negative number you did not expect.

### Casting values back to signed int

If we explicitly cast the result back to a signed integer, then we might get something usable again.

```c++
unsigned int x = 10;
unsigned int y = 20;
std::cout << (int)(x-y) << std::endl;

// Or:
int z = x - y;
std::cout << z << std::endl;
```

### Container sizes are often unsigned

We often refer to a generic data structure class as a "container". The C++ Standard Template Library (STL) provides many of these, such as std::vector.

Many of these class types have a `size()` member variable that returns the number of items the container currently holds. It's important to note that in many cases, this will give you the size in an unsigned integer type.

Here is an example where the compiler will warn you it's comparing the signed integer i with the unsigned integer returned by `size()`:

```c++
std::vector<int> v = {1,2,3,4};
for (int i=0; i < v.size(); i++) {
    std::cout << v[i] << std::endl;
}
```

The unsigned value can be cast to signed value:

```c++
std::vector<int> v = {1,2,3,4};
for (int i=0; i < (int)v.size(); i++) {
    std::cout << v[i] << std::endl;
}
```

In practice, for this code to actually be fully robust, you'd also need to check `i` against the maximum limit for an integer of its type, and make sure that the container never grew that large either.
