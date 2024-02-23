# Graph Algorithms

## Graph Traversals

Objective: Visit every vertex and every edge in the graph.

Purpose: Search for interesting sub-structures in the graph.

With trees, there is an order, and an obvious starting point, as well as a notion of completeness. Graphs, however, are unordered, and there is no obvious starting point nor any notion of completeness.

### BFS Traversals

Using a queue. Cross edges are not discovery edges.

Does this implementation handle disjoint graphs? Yes

Does this implementation detect a cycle? Yes

What is the running time? $O(n + m)$

BFS can be used to find the shortest path, only from the starting point to another vertex; not between any two vertices.

### DFS Traversals

Implementation without making use of any data structure. Back edges are not discovery edges.

Running times:

- Labelling vertices: $2*n$ => $O(n)$
- Labelling edges: $2*m$ => $O(m)$
- Labelling queries: $n$ => $O(n)$
- Labelling queries: $sum(deg(v)) = m$ => $O(m)$

Total running time: $O(n + m)$

*Question:* Which of these algorithms can be used to count the number of connected components in a graph? Both

- Count the number of times a breadth first traversal is started on every vertex of a graph that has not been visited by a previous breadth first traversal.
- Count the number of times a depth first traversal is started on every vertex of a graph that has not been visited by a previous breadth first traversal.

*Question:* Which elements encountered by a breadth first search can be used to detect a cycle in the graph?

Previously visited vertices that have been encountered again via a previously unexplored edge.

(A breadth first traversal returns a spanning tree of each connected component of the graph. Any edge that is not part of the breadth first search (e.g. not marked discovered) will connect one portion of the tree to another forming a cycle. Thus all unexplored edges, including ones ignored because they reach a previously visited vertex will create a cycle if added to the breadth first search.)

*Question:* A breadth first traversal starting at vertex v1 of a graph can be used to find ... the shortest path (in terms of # of edges) between vertex v1 and any other vertex in the graph.

(A breadth first search adds vertices connected to the current frontier of vertices using a queue, so that all vertices a given number of edges away from the start vertex must have been processed through the queue before the next wave of vertices can be processed. Since vertices are added in this edge-length order, the breadth first traversal finds the shortest path from the start vertex to any vertex, but this is only true for the start vertex.)

*Question:* Which traversal method has a better run time complexity to visit every vertex in a graph?

Both have the same run time complexity; $O(n + m)$ for $n$ vertices and $m$ edges.

## Minimum Spanning Trees

Input: Connected, undirected graph $G$ with edge weights (unconstrained, but must be additive)

Output: A graph $G'$ with the following properties:

- $G'$ is a spanning graph of $G$
- $G'$ is a tree,connected and acyclic (note  a connected directed graph with no cycles may not always be a tree)
- $G'$ has a minimal total weight among all spanning trees

*Question:* Is a connected directed graph with no cycles always a tree?

For example, a directed graph such as `A -> B, A -> C, B -> D, C -> D` is connected and has no cycle, but is not a tree because there are multiple paths from vertex `A` to vertex `D`.

### Kruskal's Algorithm

Running time: $m * log(m)$

### Prim's Algorithm

Running time:

| | Adjacency Matrix | Adjacency List |
|:---|:---|:---|
| Heap | $O(n^2 + m * log(n))$ | $O(n * log(n) + m * log(n))$ |
| Unsorted Array | $O(n^2)$ | $O(n^2)$ |

## Shortest Path Algorithms

### Dijkstra's Algorithm

Dijkstra's algorithm finds the shortest weighted path, if it exists, between a start vertex and any other vertices in a directed graph.

#### Running Time

$O(m + n * log(n))$ is the running time for Dijkstra's algorithm to find the shortest path, if it exists, from a vertex to all of the other vertices in a weighted, directed graph of $n$ vertices and $m$ edges.

#### Edge Cases

*Question:* For which situation described here can Dijkstra's algorithm sometimes fail to produce a shortest path? You would want to avoid using Dijkstra's algorithm in this situation?

A connected graph where some of the edge weights are negative and some have weight zero.

There is nothing wrong with the edge weights of zero, but the negative weights are a problem. Dijkstra's algorithm, without modifications, achieves its fast running time by making certain assumptions about which paths are best. If it encounters an edge with negative weight, the assumptions fail, and it may not correctly identify the shortest path.

Some people modify Dijkstra's algorithm to iterate when negative edge weights are encountered, to make corrections. However, this causes the algorithm to run very slowly in the worst case, and it's not part of the classical algorithm.

(As a separate note, if there is any graph where a cycle has weights that sum to a negative value overall, then other shortest path algorithms can also fail to find a shortest path even if they are able to handle negative edge weights in some cases. That's because the graph may have paths with infinitely negative weight.)

### Landmark Path Problem

*Question:* Suppose you are given an undirected simple graph with unweighted edges, and  for a particular specification of three vertices uu, vv, and ww, you want to find the shortest path from uu to ww that goes through vv as a landmark. What is the most efficient method that can find this?

A single run of breadth-first search from vv.

A single breadth-first search from the landmark vertex finds the shortest paths from it to the start vertex and the end vertex, and since the edges are undirected, their combination is the shortest path from start to end that also visits the landmark.

It's not necessary to use Dijkstra's algorithm in this case since the edges are unweighted.
