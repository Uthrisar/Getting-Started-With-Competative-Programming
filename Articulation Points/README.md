Articulation Points Finder in a Graph
This program finds the articulation points in an undirected graph. An articulation point is a vertex in a graph, which, when removed, increases the number of connected components in the graph. In other words, it is a critical point that disconnects parts of the graph when removed.

Algorithm
The program implements Tarjan's Algorithm using Depth First Search (DFS) to find articulation points.

Key Concepts:
Discovery Time (st[]): The time when a node is first visited.
Low Value (low[]): The smallest discovery time reachable from a node, considering back edges.
Articulation Point: A node u is an articulation point if:
u is the root of the DFS tree and has two or more children.
u has a child v such that no vertex in the subtree rooted at v can connect to an ancestor of u.
Time Complexity:
The algorithm runs in O(V + E) where V is the number of vertices and E is the number of edges.

![Graph of Articulation Points](https://i.sstatic.net/5Uc3C.png)
