# Object-Oriented Programming in C++

## Template Types

A template type is a special type that can take on different types when the type is initialized.

## Templated Functions and Classes

A template variable is defined by declaring it before the beginning of a class or function:

```c++
template <typename T>
int max(T a, T b) {
  if (a > b) return a;
  return b;
};

cout << max(1, 2) << " " << max('a', 'b') << endl;

template <typename S>
class Class { ... };
```

## Inheritance

A base class is a generic form of a specialized, derived class.
