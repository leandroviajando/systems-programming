# Linear Structures

## Arrays

*An array stores data in blocks of sequential memory.*

Limitations:

- All data in an array must be of the same type.
- Arrays have a fixed capacity.

The only way to add another element is to allocate a new, larger array and copy over all of the data - which is costly (e.g. vectors).

## Linked Memory

Linked memory stores data in nodes linked together by links / pointers to the location in memory of the next list node. A basic linked memory data structure is a linked list.

While an array has a fixed capacity, a list is a more flexible data structure that does not need to be resized and whose capacity is bounded only by the memory available on the system.

## Runtime Analysis

Access Time Complexity:

- Accessing a given index in an array via an offset formula has constant time complexity: $O(1)$
- Accessing a given element in a list, traversing every element in the list to reach the index, has linear time complexity (based on the size of the list): $O(n)$

Time Complexity of resizing an array depends on the strategy used, e.g.:

- adding two slots is $O(n^2)$
- doubling capacity is $O(n)$

## Array and List Operations

Inserting an element at the front of an array or list is $O(1)$.

Finding an element in an array or a list is $O(n)$. This is linear search.

However, for an array, this can be improved by first sorting the array and using binary search which run ins $O(log(n))$.

Inserting an element between two other elements or deleting a given element is $O(1)$ in a list but $O(n)$ (/ $O(1)$ in amortized running time) in an array.

## Queues

A queue is a FIFO data structure.

A structure's **Abstract Data Type (ADT)** is how data interacts with the structure.

A queue's ADT consists of four operations: create, push, pop, empty.

It may be implemented with an array or a doubly-linked list (with a head and tail pointer).

Both an array-based and a list-based implementation can be built to run in constant, $O(1)$ running time.

`push()` and `pop()` run in amortized constant time $O(1)$ for an array, but if there is a large number of calls to `push()` and `pop()` this will ensure that the cost of resizing the array is properly amortized by the benefits of the array.

## Stacks

A stack is a LIFO data structure.

The stack ADT consists of the same operations as the queue ADT; with (amortized) $O(1)$ running time complexity for list-based and array-based implementations.
