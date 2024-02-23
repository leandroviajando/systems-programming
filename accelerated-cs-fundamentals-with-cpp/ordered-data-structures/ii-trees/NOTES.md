# Trees

A tree is a linked data structure with a sense of ancestry (parents, children, siblings, and more)!

Each element is a node; each connection between two nodes is an edge. Nodes that contain no outgoing nodes are leaf nodes.

A tree is a rooted, directed and cyclic structure. It must

- have a root
- have directed edges
- not have a cycle

## Binary Trees

A binary tree is a tree where *every node has at most two children.*

The **height** of a binary tree is the number of edges in the longest path from the root to a leaf.

A binary tree is **full** if and only if every node has either zero children or two children.

A binary tree is **perfect** if and only if all interior nodes have two children, and leaves are at the same level.

A binary tree is **complete** if and only if the tree is perfect up until the last level, and all leaf nodes on the last level are pushed to the left.

Note a tree may be complete but not full, or full and not complete.

## Tree Traversals

- Pre-Order
- In-Order
- Post-Order
- Level-Order

## Binary Search Trees

A BST is an *ordered binary tree capable of being used as a search structure.*

A binary tree is a BST if and only if for every node in the tree:

- Nodes in the left subtree are less than itself
- Nodes in the right subtree are greater than itself.

The In-Order Predecessor (IOP) is the previous node in an in-order traversal of a BST.

There are $n!$ different ways to create a BST with the same data.

- The worst-case BST will have a height proportional to the number of nodes.
- An average BST will have a height proportional to the logarithm of the number of nodes.

ADT: find, insert, remove, empty

| Operation | BST Avg Case | BST Worst Case | Sorted Array | Sorted List |
|:-----|:-----|:-----|:-----|:-----|
| find | $O(log(n))$ | $O(n)$ | $O(log(n))$ | $O(n)$ |
| insert | $O(log(n))$ | $O(n)$ | $O(n)$ | $O(n)$ |
| remove | $O(log(n))$ | $O(n)$ | $O(n)$ | $O(n)$ |

## Balanced BSTs

A balanced BST is a BST where every node's balance factor has a magnitude of $0$ or $1$.

BST rotations restore the balance property to a tree after an insert or remove causes a BST to be out of balance: Left, Right, Left-Right, Right-Left.

BST rotations

- are local operations
- and as such, do not impact the broader tree
- run in $O(1)$ time
- are called AVL (Adelson-Vesky and Landis) trees

## AVL Trees

An AVL tree is an implementation of a BST, adding two key ideas:

- maintains the height at each node
- maintains the balance factor after insert and remove

To quickly compute the balance factor, AVL trees store the height of every node as part of the node itself.

## B-Trees

The objective of a B-Tree is to *minimize the number of reads.*

For a B-Tree of order $m$:

1. All keys within a node are in sorted order.
2. Each node contains no more than $m-1$ keys.
3. Each internal node can have at most m children, so a B-tree of order $m$ is like an
4. $m$-way tree.
      - A root node can be a leaf or have $[2, m]$ children.
      - Each non-root, internal node has $[ceil(m/2), m]$ children.
5. All leaves are on the same level.

The height of the B-Tree determines the maximum number of seeks possible in search data. And the height of the structure is $log(n)$. Therefore, the number of seeks is no more than $log_m(n)$.

*Question:* What are valid reasons to choose the B-Tree representation over a standard AVL binary search tree?

- B-Trees require fewer block read accesses for tree operations.
- B-Trees work faster in networked cloud environments than do AVL trees.
- B-Trees run faster on large data sets than do AVL trees.

*Question:* What statements can be made about a B-Tree of order `m`?

- Each node can have at most one more child than key.
- Any node that is not the root or a leaf holds at least half of the total number of keys allowed in a node.
- All leaf nodes are at the same level of the B-Tree.

*Question:* If a B-Tree is completely filled, i.e. every node holds its maximum number of keys and all non-leaf nodes have the maximum number of children, then what happens when an additional key is inserted into the B-Tree?

After searching for the leaf node where the new key should go, the leaf is split in half as two separate leaf nodes, and then the middle value is thrown up to the layer above as an inserted key, and this insertion and rebalancing repeats until a new root key rises to the top, which adds a layer to the tree.
