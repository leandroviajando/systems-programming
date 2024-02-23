# Disjoint Sets

A disjoint set is a series of sets which are disjoint from one another, but every single element within a set is considered to be equivalent within that set. Each set must have one distinct set ID.

*Question:* What happens when you take the union of two disjoint sets that contain the same value? This is not possible. Two different disjoint sets by definition can never share the same value.

**Find:** For example, given three disjoint sets $\{1,3,5,7\}$, $\{2,8\}$ and $\{4,6\}$, the value $3$ would be referenced by the set $\{1,3,5,7\}$.

**Union**: The union of $\{1,3,5,7\}$ and $\{2,8\}$ would be $\{1,2,3,5,7,8\}$.

As you read further literature in computer science, you'll notice that the "disjoint sets" data structure is also sometimes referred to as the **"union-find"** data structure, because of its primary methods, "union" and "find".

In C and C++, the word "`union`" is reserved for a specific language feature, so you can't use "union" as a name for a variable or function. Instead you have to use a variant such as "`set_union`".

## Naive Implementation

An array or hash table mapping every element to its set ID.

This gives $O(1)$ runtime for the find operation but $O(n)$ complexity for the union operation (have to traverse the whole array to find all elements of two arrays).

## UpTrees

An array mapping every element to either $-1$ (/ incrementally, the negative of the subtree's height or size, see below) or to the element that is the set's ID.

### Find

The find operation runs in $O(h) <= O(n)$ (where in the worst case there is only one leaf in each layer of the tree).

```c++
int DisjointSets::find(int i) {
  if (s[i] < 0) return i;
  else return _find(s[i]);
}
```

### Smart Union

- Union by Height: Keep the height of the tree as small as possible.
- Union by Size: Minimize the number of nodes that increase in height.

Both guarantee that height of the tree is $log(n)$. Thus, *either strategy results in the same overall time complexity.*

### Path Compression

When traversing the up-tree from an element to its root, if any elements in the traversal (including the first element, but excluding the root itself) do not point directly to the root as their parent yet, they will have their parent pointer changed to point directly to the root.

Path compression thus only flattens the lineage of nodes in an up-tree from an element to the root, and not all of the elements in the up-tree every time. This has amortized benefits as the data structure is optimized over the process of several union and find operations.

In a disjoint sets data structure implemented with smart unions and path compression on find, any sequence of $m$ union and find operations result in the worst case running time of $O(m *log*(n))$, where $n$ is the number of items and $log*(n)$ is the iterative log (which is effectively constant time).
