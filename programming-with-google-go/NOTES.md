# Programming with Google Go

## 2.1 Functions and Organization

### Function Parameters and Return Values

Parameters are listed in parentheses. Arguments are supplied in the call.

### Cally by Value

Passed arguments are copied to parameters, and modifying the parameters has no effect outside the function.

```go
func foo(y int) {
    y += 1
}

func main() {
    x := 2
    foo(x)
    fmt.Print(x)
}
```

- Advantage: Data encapsulation
- Disadvantage: Copying time (for large objects)

### Call by Reference

The called function has direct access to the caller variables.

```go
func foo(y *int) {
    *y += 1
}

func main() {
    x := 2
    foo(&x)
    fmt.Print(x)
}
```

- Advantage: No copying time (e.g. sort an array)
- Disadvantage: Data encapsulation (difficult to debug)

### Passing Arrays and Slices

Array arguments are copied - which can be a problem if the array is big.

It is possible to pass array pointers. But this is messy and unnecessary.

Slices contain a pointer to the array. Passing a slice copies the pointer.

```go
func foo(sli []int) {
    sli[0] += 1
}

func main() {
    arr := []int{1, 2, 3}
    foo(arr)
    fmt.Print(arr)
}
```

### Well-Written Functions

Supporting debugging:

1. Functions need to be understandable
   - Determine if actual behaviour matches desired behaviour
2. Data need to be traceable
   - Where did the input data come from?
   - Global variables (and pointers) complicate this

### Guidelines for Functions

- Naming
- Single responsibility
- Cohesion
- Few parameters
- Short
- Low control-flow complexity -> partition conditionals

## 2.2 Function Types

### First Class Values

Functions can be treated like any other type:

- assigned to a variable
- created dynamically
- passed as arguments
- returned as values
- stored in data structures

### Lexical Scoping

The environment of a function is the set of all names that are valid inside a function.

This includes names defined in the block where the function is defined.

```go
var x int
func foo(y int) {
    z := 1
}
```

### Closures

Thus, when functions are passed / returned, their environment comes with them!

```go
func wrapper(x, y int) func(int) int {
    return func(z int) int {
        return math.Pow(x + y, z)
    }
}
```

### Variadic Arguments

Functions can take a variable number of arguments, which are treated as a slice inside the function.

```go
func max(vals ...int) int {}
```

A slice can be passed to a variadic function like so:

```go
func main() {
    max([]int{1, 2, 3}...)
}
```

### Deferred Function Calls

Function calls can be deferred until the surrounding function completes. This is typically used for clean-up activities.

```go
func main() {
    defer fmt.Println("Bye!")

    fmt.Println("Hello!")
}
```

Note arguments of a deferred call are evaluated immediately.

```go
func main() {
    i := 1
    defer fmt.Println(i+1)
    i++
    fmt.Println("Hello!")
}
```

## 2.3 Object Orientation

### Classes

A class is a collection of data fields and functions that share a well-defined responsibility.

Classes are a template; they contain data fields, no data.

### Encapsulation

Go can only hide data or methods in a package (using lower-case naming) from other packages, but not from other modules within packages.

### Support for Classes

In Go, struct types compose data fields, and can have functions associated with them.

Such receivers are passed implicitly as an argument to the method.

- Receivers are passed by value / copy
- Pointer receivers can modify the data in the struct

### Pointer Receivers, Referencing, Dereferencing

Note there is no need to dereference (`*p`) pointer receivers inside methods.

```go
func (p *Point) OffsetX(v int) {
    p.x += v
}
```

Nor to reference pointers when calling a method on a pointer receiver.

```go
func main() {
    p := Point{3, 4}
    p.OffsetX(5)
    fmt.Println(p.x)
}
```

This is handled by the compiler.

## 2.4 Interfaces for Abstraction

### Polymorphism

Polymorphism is the ability of an object to have different forms depending on the context.

This can be achieved with inheritance and method overriding.

### Interfaces

Go makes use of implicit interfacing to achieve polymorphism.

### Interface vs. Concrete Types

Interfaces allow for abstraction of the exact representation of the data and methods.

### Using Interfaces

Using an empty interface means the function accepts any type as a parameter.

### Type Assertions

```go
func DrawShape(s Shape2D) bool {
    switch sh := s.(type) {
    case Rectangle:
        DrawRectangle(sh)
    case Triangle:
        DrawTriangle(sh)
    }
}
```

### Error Handling

```go
type error interface {
    Error() string
}

type FileNotFoundError struct {
    fileName string
}

func (e FileNotFoundError) Error() string {
    return "File " + e.fileName + " not found"
}

f, err := os.Open("f.txt")
if err != nil {
    switch e := err.(type) {
    case FileNotFoundError:
        fmt.Println(err)
        return
    default:
        panic(err)
    }
}
```

## 3.1 Why Use Concurrency?

### Parallel Execution

Parallel execution requires replicated hardware.

Some tasks are parallelizable, and some are not.

### Von Neumann Bottleneck

A processor is idle for a certain amount of time while memory is accessed.

If parallelism is not an option, performance can be improved by designing faster processors and processors with more memory.

Moore's Laws predicts transistor density on microchips to double every two years.

Smaller transistors switch faster, and exponential increases in density would lead to exponential increases in speed.

### Power Wall

Transistors consume power when they switch.

Increasing transistor density leads to increased power consumption. (Small transistors use less power, but density scaling is faster.)

High power leads to high temperature. But air colling (fans) can only remove so much heat.

Voltage should scale with transistor size. This keeps power consumption and temperature low.

Problem: voltage can't go too low.

Cannot increase frequency, but can still add processor cores, without increasing frequency.

Thus the need for parallel execution to exploit multi-core systems.

### Concurrent vs. Parallel

- Parallel tasks must be executed on different hardware.
- Concurrent tasks may be executed on the same hardware - only one task is actually executed at a time.

Mapping tasks to hardware will therefore look different for parallel and concurrent executions.

The programmer makes parallelism possible by determining which tasks can be executed in parallel, but does not determine the hardware mapping.

Hardware mapping is handled by the operating system and the Go runtime scheduler, and depends on factors such as location of data and communication costs.

### Hiding Latency

Concurrency can improve performance even without parallelism by executing another thread while a thread is waiting for I/O, for example.

## 3.2 Concurrency Basics

### Processes

A process is an instance of a running programme with unique memory and (stack, heap), virtual address space, and registers (programme counter, data register, stack register).

Operating systems allow many processes to execute concurrently.

### Scheduling

Processes are switched quickly (in the range of 20ms) with fair access to resources (CPU, memory), giving the user the impression of parallelism.

Such a switch from one process to another is called a context switch.

### Threads and Goroutines

A thread is a light-weight process sharing some context (virtual memory, file descriptors) with other threads.

Thus, many threads can exist within one process, and the OS will schedule threads rather than processes.

In Go, the main thread within a process is able to execute many Goroutines within a single OS thread.

The Go runtime scheduler is like a little OS inside a single OS thread, responsible for scheduling the thread's Goroutines.

### Interleaving

The order of execution within tasks is known. The order of execution within concurrent tasks is not known.

Therefore, the outcome of a concurrent task depends on non-deterministic ordering.

### Race Conditions

When multiple goroutines share access to a variable or resource a race condition may occur.

## 3.3 Threads

### Goroutines

One goroutine is created automatically to execute the `main` programme. Other goroutines are created using the `go` keyword.

### Exiting Goroutines

A goroutine exits when its code is complete.

When the main goroutine is complete, all other goroutines exit.

A goroutine may not complete its execution if main completes early.

```go
func main() {
    go fmt.Println("New routine")
    time.Sleep(100 * time.Millisecond)
    fmt.Println("Main routine")
}
```

However, adding a delay to wait for a goroutine is bad because timing is non-deterministic.

Need formal synchronization constructs.

### Wait Groups

The `sync` package contains functions to synchronize between goroutines.

`sync.WaitGroup` forces a goroutine to wait for other goroutines using a counter.

```go
func foo(wg *sync.WaitGroup) {
    fmt.Println("New routine")
    wg.Done()
}

func main() {
    var wg sync.WaitGroup

    wg.Add(1)
    go foo(&wg)

    fmt.Println("Main routine")

    wg.Wait()
}
```

### Communication

Goroutines usually work together to perform a bigger task, and often need to send data to collaborate.

```go
func prod(i int, j int, c chan int) {
    c <- i * j
}

func main() {
    c := make(chan int)

    go prod(1, 2, c)
    go prod(3, 4, c)

    a := <- c
    b := <- c

    fmt.Println(a * b)
}
```

### Blocking on Channels

Unbuffered channels (the default) cannot hold data in transit.

- Sending blocks until data is received.
- Receiving blocks until data is sent.

Channel communication is synchronous. Therefore, blocking is the same as waiting for communication.

### Buffered Channels

Channels can contain a limited number of objects (default capacity is 0, i.e. unbuffered), which can be specified as an optional argument.

```go
c := make(chan int, 3)
```

- Sending only blocks if the buffer is full.
- Receiving only blocks if the buffer is empty.

Buffering is useful if the sender and receiver do not need to operate at exactly the same speed; i.e. a speed mismatch is acceptable but the average speeds must still match.

## 3.4 Synchronized Communication

### Blocking on Channels

It is common to iteratively receive from a channel (one iteration each time a new value) is received.

```go
for i := range c {
    fmt.Println(i)
}
```

### Select

Or there may be a choice of which data to use and what to do with it, including a channel for aborting, or a default operator to avoid blocking.

```go
select {
    case a = <- c1:
        fmt.Println(a)
    case b = <- c2:
        fmt.Println(b)
    case <- abort:
        return
    default:
        fmt.Println("nop")
}
```

### Mutual Exclusion

Concurrency is at machine-code level; for example, `i = i + 1` might be three machine instructions: `read i`, `increment`, `write i`.

Goroutines sharing variables concurrently can cause problems and unexpected results.

Such code segments should therefore be mutually exclusive.

A function is concurrency-safe if it can be invoked concurrently without interfering with other goroutines.

### Mutex

`sync.Mutex` ensures mutual exclusion using a binary semaphore.

- Flag up: shared variable is in use.
- Flag down: shared variable is not in use.

```go
var i int = 0
var mutex sync.Mutex

func inc() {
    mutex.Lock()
    i = i + 1
    mutex.Unlock()
}
```

- If the lock is already taken by another goroutine, `Lock()` blocks until it is available.
- When `Unlock()` is called, a blacked `Lock()` can proceed.

### Once Synchronization

Innitialization must happen once and before everything else.

```go
var wg sync.WaitGroup
var once sync.Once

func main() {
    wg.Add(2)
    go doStuff()
    go doStuff()

    wg.Wait()
}

func doStuff() {
    once.Do(setup)

    fmt.Println("hello")

    wg.Done()
}

func setup() {
    fmt.Println("Init")
}
```

Even if it is called in multiple goroutines, the function is executed only once.

Calls to `once.Do()` block until the first returns.

### Deadlock

Synchronization causes the execution of different goroutines to depend on each other.

Circular dependencies where two channels wait on each other can cause goroutines to block.

```go
func doStuff(ch1 chan int, ch2 chan int) {
    <- ch1
    ch2 <- 1

    wg.Done()
}

func main() {
    ch1 := make(chan int)
    ch2 := make(chan int)
    wg.Add(2)
    go doStuff(ch1, ch2)
    go doStuff(ch2, ch1)
    wg.Wait()
}
```

Golang runtime automatically detects when all goroutines are deadlocked, but cannot detect when a subset of goroutines are deadlocked.
