# Heaps

A data structure that can remove the minimum value, and do so efficiently.

Specifically, a min-heap is a *complete binary tree such that each node's value is greater than its parent's value (i.e. each node in turn is a min-heap).*

Or, in other words, a non-empty binary tree is a min-heap if the root is less than either or both of its children (if any), and the subtrees of its children are min-heaps.

Note just under half of a complete binary tree's nodes are leaf nodes: About half of the nodes are leaf nodes, about a quarter have height 1, about an eighth have height 2, about a sixteenth have height 3, and so on.

Thus there is no need for pointers. This data structure can easily be implemented in memory as an array where every node's parent can be found by integer division: $i/2$ (assuming array indexing starts at 1 rather than 0, to simplify the maths).

## HeapInsert

If the number is smaller than its parent, continually swap the inserted number with its parent until the new value is in a node where it is greater then the value of its parent. This works in $O(log(n))$ time.

Doubling the size of the array when needed is an operation of amortized complexity $O(1)$.

## RemoveMin

When removing the minimum (i.e. the root node), move the last element in the array to the first index (i.e. the root node), and swap / heapify it down until the tree is in order again.

```c++
template <class T>
void Heap<T>::_heapifyDown(int index) {
  if (!_isLeaf(index)) {
    T minChildIndex = _minChild(index);
    if (item_[index] > item_[minChildIndex] ) {
      std::swap( imem_[index], item_[minChildIndex]);
      _heapifyDown(minChildIndex);
    }
  }
}
```

The maximum number of the times the operation will be called is one plus the height of the node, i.e. $O(log(n))$.

## BuildHeap

Create a complete tree of the items in any order, then call heapifyDown on every non-leaf node from the bottom of the tree up to the root.

The run-time of calling heapifyDown on a node is proportional to the height of the node. About half of the nodes are leaf nodes, about a quarter have height 1, about an eighth have height 2, about a sixteenth have height 3, and so on. This summation of heights converges to $n$, the number of nodes in the tree. Hence running heapifyDown on every non-leaf node, and building a heap this way, has a run-time complexity of $O(n)$.

## HeapSort

1. Build heap, i.e. load the data in any order into a complete tree ($O(n)$)
2. Run heapifyDown on every non-leaf node
3. Remove the root node

HeapSort runs in $n * log(n)$ time.
