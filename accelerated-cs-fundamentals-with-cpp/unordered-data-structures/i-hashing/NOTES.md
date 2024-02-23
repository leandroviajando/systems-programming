# Hashing

A hash table consists of three things:

- A hash function mapping inputs to an array index
- An array storing the data
- A collision handling strategy

## Hash Functions

An `onto` function is the ideal case where every element in the domain can be mapped to a unique value.

Characteristics of a good hash function:

- Computation time: must run in $O(1)$
- Deterministic: must always generate the same output given the same input
- Satisfy the Single Uniform Hashing Assumption (SUHA): values must be evenly distributed across thte entire key space, i.e. $P(h(a) == h(b)) = 1 / N$ for any $a != b$

For example, `int h(uint key) { return key & 7; }`

- runs in $O(1)$
- is deterministic, always generating the same output given the same input
- has a uniform chance of collision

Note that in binary, the number $7$ is $0000...0111$. (The leading digits are all zero, followed by three 1 digits, because these place values represent $4+2+1$.) When you do "`key & 7`", the result will have leading zeros, and the rightmost three digits will be the same as those of key. Because this results in values between $0$ and $7$, it's similar to taking the remainder of division by $8$. That is, "`key & 7`" should give the same result as "`key % 8`".

**Bitwise operations** like this can be faster than arithmetic operations, but you have to be careful about the specific data types and the type of computing platform you are compiling for. Note that this trick only works for some right-hand values as well, based on how they are represented in binary. These tricks are not always portable from one system architecture to another.

## Collision Handling

### Separate Chaining

Using a linked list, simply chain values that collided; i.e. there may be more than one element at each index.

### Linear Probing

Insert in the next unfilled space.

Downside: Even using a good hash function, contiguous portions of the array will become filled, causing a lot of additional probing in search of the next available unused element in the array.

### Double Hashing

Double hashing reduces the clumping that can occur with linear probing.

On collision, use a second hash function.

## Runtime Analysis

| Operation | SUHA | Worst Case |
|:---|:----|:----|
| Insert | $O(1)$ | $O(1)$ |
| Remove / Find | $O(\alpha) = O(n/N)$ | $O(n)$ |

where the load factor $\alpha = n / N$, the number of elements in the table divided by the size of the table itself

Therefor, as long as the load factor $\alpha$ can be maintained to stay below $.6$ the runtime is extremely fast. After that point, performance decreases exponentially.

To do so, the array's size can be doubled with rehashing.

Which collision resolution strategy is better?

- Big records: Separate Chaining
- Structure speed: Double Hashing

What structure do hash tables replace? Dictionaries

**Hash tables are great if a lot of lookup operations will be performed.**

Otherwise, an alternative implementation, is an AVL or red-black tree often used to implement a map.

*Question:* Which of the following data structures would be the better choice to implement a memory cache, where a block of global memory (indicated by higher order bits of the memory address) are mapped to the location of a block of faster local memory?

Double hashing would be a good strategy because the cache addresses are quite small and compactly stored in the array. Furthermore, double hashing is more efficient than linear probing, which suffers from clumping.

*Question:* Which of the following data structures would be the better choice to implement  a dictionary that not only returns the definition of a word but also returns the next word following that word (in lexical order) in the dictionary?

While the AVL tree needs O(log n) time to find the definition of the word, which is worse than the performance of a hash table, the AVL tree can find the next word in lexical order in O(log n) time whereas any hash table would need O(N) steps to find the next word in lexical order.
