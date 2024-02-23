# Graphs

$G = G(V, E)$ where $|V| = n$, $|E| = m$

Incident edges $I(v) = \{ (x, v) \in E \}$

$Degree(v) = |I|$

Adjacent vertices $A(v) = { x: (x, v) \in E }$

A **path** is a sequence of vertices connected by edges.

A **cycle** is a path with a common beginning and end vertex.

A **simple graph** is a graph with no self loops or multi-edges.

For example, $G = ( V = (a,b,c), E = ((a,b),(b,c),(a,c)) )$ is a simple graph, while $G = ( V = (a,b,c), E = ((a,b), (a,c), (b,a), (b,c), (a,c), (b,c)) )$ is not because the same edge between a and b appears twice.

For a simple graph with $n$ vertices, the worst-case (largest-possible) number of edges is $O(1/2 * n^2) = O(n^2)$

## The Graph ADT

1. Data
   - Vertices / nodes
   - Edges
   - Some data structure maintaining the structure between vertices and edges.
2. Functions
   - `insertVertex(Key k);`
   - `insertEdge(Vertex v1, Vertex v2, Key k);`
   - `removeVertex(Vertex v);`
   - `removeEdge(Vertex v1, Vertex v2);`
   - `incidentEdges(Vertex v);`
   - `areAdjacent(Vertex v1, Vertex v2);`
   - `origin(Edge e);`
   - `destination(Edge e);`

## Complexity Analysis

| Operation | Edge List | Adjacency Matrix | Adjacency List |
|:---|:---|:---|:---|
| Space | $n + m$ | $n^2$ | $n + m$ |
| `insertVertex(v)` | $1$ | $n$ | $1$ |
| `removeVertex(v)` | $m$ | $n$ | $deg(v)$ |
| `insertEdge(v1, v2, k)` | $1$ | $1$ | $1$ |
| `removeEdge(v1, v2)` | $1$ | $1$ | $1$ |
| `incidentEdges(v)` | $m$ | $n$ | $deg(v)$ |
| `areAdjacent(v1, v2)` | $m$ | $1$ | $min(deg(v1), deg(v2))$ |

*Question:* Which graph representation has a better worst-case storage complexity than the others for storing a simple graph of n vertices?

All three graph representations have the same worst-space storage complexity for a simple graph of n nodes.

*Question:* Suppose you have a rapid data feed that requires you to add new data point vertices quickly to a graph representation. Which graph representation would you NOT want to utilize?

The adjacency matrix requires linear time, O(n), to add a vertex because the addition requires new entries to be placed in a new row and a new column of the matrix, and there are n elements in the new row and n elements in the new column. This means that as the number of vertices grows in the graph, it will take longer to add a new vertex, which is not a very good choice when processing a data feed.

*Question:* Suppose you have a rapid data feed that requires you to remove existing data point vertices (and any of their edges to other vertices) quickly to a graph representation. Which graph representation would you WANT to utilize?

Since the adjacency list has a list of the edges the removed vertex shares with other vertices, it only needs time proportional to the degree of the removed vertex. In the worst case, that vertex could be connected to all of the other vertices and so require O(n) time, but in the typical case the degree will be less and the adjacency list is a better choice than the adjacency matrix.

*Question:* Suppose you want to implement a function called neighbors(v) that returns the list of vertices that share an edge with vertex v. Which representation would be the better choice for implementing this neighbors() function?

The adjacency list requires a simple walk through the list of pointers to adjacent edges to find the neighboring vertices. This representation has an "output sensitive" running time meaning it runs as fast as possible based on the minimum amount of time needed to output the result.

*Question:* Suppose you want to implement a function called neighborsQ(v1,v2) that returns true only if vertices v1 and v2 share an edge. Which representation would be the better choice for implementing this neighborsQ() function?

The neighborsQ(v1,v2) function can simply lookup the appropriate v1,v2 entry in the adjacency matrix, which takes constant O(1) time. This representation supports the fastest method for implementing this query.

*Question:* Which graph representation would be the best choice for implementing a procedure that only needs to build a graph from a stream of events?

The Edge List performs worse in general than the Adjacency Matrix and the Adjacency List representations, but it is much simpler and easier to implement. It also takes less space than the alternatives, and can insert vertices and edges in constant time. The adjacency list can also insert vertices and edges in constant time, but if those are the only operations needed, then one need not waste space and additional code on building the adjacency list on top of the edge list.
