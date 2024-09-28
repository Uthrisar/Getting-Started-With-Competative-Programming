
# Minimum Time Valid Walk

## Problem Statement
In the Republic of AtCoder, there are **N** towns (numbered from 1 to N) and **M** one-way roads connecting these towns. Each road has a certain travel time associated with it, and some roads may connect a town to itself. The goal is to determine, for each town, whether there exists a **valid walk** that starts and ends at the same town and to find the **minimum time** required for such a walk.

### Problem Requirements
1. A **valid walk** must start at a town, traverse through one or more roads, and return to the starting town.
2. For each town, output:
   - The minimum time required to complete a valid walk starting and ending at that town.
   - `-1` if no valid walk exists for that town.

## Approach
1. Construct a graph for the given roads using adjacency lists.
2. Use **Dijkstra's algorithm** to find the shortest paths from each town to all other towns.
3. Reverse the graph and run **Dijkstra's algorithm** again to calculate the shortest return path to the starting town.
4. Check if a valid cycle exists using either self-loops or combined forward and backward paths.
5. For each town, output the minimum time for a valid walk or `-1` if no cycle is possible.

## Visual Representation
Below is a visual representation of an example graph with 4 towns and 5 roads:

![Graph Example](graph_example.png)

## Solution Details
The implementation uses a graph traversal technique with two Dijkstra runs for each town: one on the original graph and another on the reversed graph. This allows us to determine the shortest cycle starting and ending at the same town. The complexity is optimized using a priority queue for the Dijkstra algorithm, making it efficient for larger inputs.

## Example
Consider a case with **4 towns** and **5 roads**:

```
4 5
1 2 10
2 3 15
3 1 5
1 4 20
4 1 25
```

Output:
```
30
-1
-1
45
```

### Explanation:
- For Town 1, the minimum cycle is `1 -> 2 -> 3 -> 1` with a total time of 30.
- For Towns 2 and 3, no valid cycle exists.
- For Town 4, the cycle is `4 -> 1 -> 4` with a total time of 45.