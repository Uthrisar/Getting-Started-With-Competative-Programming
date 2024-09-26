# Space Exploration Mission - Minimum Time Analysis

## Problem Statement

A space exploration mission has been launched by a company called **SpaceZ**. The mission has limited resources, and the company wants to explore `M` planets using `N` spaceships. Each spaceship has a defined speed and can travel to any of the planets.

The mission is considered **successful** if **at least `K` spaceships** successfully reach and explore distinct planets. Once a spaceship explores a planet, it is **closed off** to other spaceships, meaning that no other spaceship can visit the same planet.

### Time Calculation for Each Journey
For a spaceship located at coordinates `(x, y)` to reach a planet at `(p, q)`, the time `t` required is defined as:
The time for a spaceship to reach a planet is given by:

$$ t = \left\lceil \frac{(p - x)^2 + (q - y)^2}{S^2} \right\rceil $$

where `S` is the speed of the spaceship. The result `t` is in **minutes**.

## Input Format
1. The first line contains a single integer `t` representing the number of test cases.
2. For each test case:
   - The first line contains three integers: `N`, `M`, and `K`:
     - `N`: Number of spaceships
     - `M`: Number of planets
     - `K`: Minimum number of spaceships required to successfully reach distinct planets
   - The next `N` lines each contain two integers: `x` and `y` coordinates of the spaceships.
   - The following `M` lines each contain two integers: `p` and `q` coordinates of the planets.
   - The final line contains `N` space-separated integers indicating the speed `S` of each spaceship.

## Output Format
For each test case, output the minimum time (in **seconds**) required to complete the space exploration mission such that `K` spaceships explore distinct planets. If it is not possible, print `-1`.

## Constraints
- **Number of test cases:** `1 <= t <= 10`
- **Number of spaceships (N):** `1 <= N <= 200`
- **Number of planets (M):** `1 <= M <= 200`
- **Required spaceships for success (K):** `1 <= K <= N`
- **Coordinate values for ships and planets (x, y, p, q):** `0 <= x, y, p, q <= 10^6`
- **Speed of each spaceship (S):** `1 <= S <= 50`


## Example
### Input
- **1**: Number of test cases.
- **3 2 1**: Represents `N = 3` (number of spaceships), `M = 2` (number of planets), and `K = 1` (minimum number of spaceships needed).
- **1 1**: Coordinates of the first spaceship.
- **2 2**: Coordinates of the second spaceship.
- **3 3**: Coordinates of the third spaceship.
- **34 59**: Coordinates of the first planet.
- **14 20**: Coordinates of the second planet.
- **1 2 3**: Speeds of the three spaceships.

### Output
2760

### Explanation
For the given example, the goal is to have at least 1 spaceship reach a distinct planet in the minimum possible time. The spaceship at `(3, 3)` can reach the planet at `(14, 20)` in a minimum of `2760` seconds using the formula.

## Solution Approach

1. **Calculate Time Matrix:**
   - For each spaceship-planet pair, calculate the travel time using the formula:
      $t = \left\lceil \frac{(p - x)^2 + (q - y)^2}{S^2} \right\rceil$

2. **Bipartite Matching:**
   - Represent the problem as a bipartite graph where:
     - Spaceships form one set.
     - Planets form another set.
     - An edge between spaceship `i` and planet `j` exists if spaceship `i` can reach planet `j` in `t` seconds.
   - Use **binary search on `t`** to find the minimum time required to match at least `K` spaceships to distinct planets.

3. **Flow Network Construction:**
   - Build a flow network where:
     - `Source` connects to all spaceships.
     - All planets connect to the `Sink`.
     - Each spaceship-planet pair has an edge only if it can reach in `t` seconds.
   - Use **maximum bipartite matching** (or **maximum flow**) to check if `K` spaceships can reach distinct planets.

4. **Binary Search on Time:**
   - Perform binary search on the minimum time required.
   - For each middle time value `mid` in binary search, construct the flow network and check if a flow of `K` can be achieved.
   - Adjust search bounds accordingly.

## Implementation Notes
1. **Edge Cases:**
   - If `K > M`, it's impossible for `K` spaceships to explore distinct planets, so output `-1`.
2. **Graph Construction:**
   - Use adjacency lists for storing the graph.
   - Store capacities of edges as needed for the flow network.

## Code Implementation
Here’s a C++ solution outline for the problem:

```cpp
#include <bits/stdc++.h>
#define INF 1e16
using namespace std;

vector<int> graph[402];
long long capacity[402][402], flow_passed[402][402];
vector<int> parent(402);
vector<long long> path_flow(402);

bool find_path(int src, int sink) {
    fill(parent.begin(), parent.end(), -1);
    fill(path_flow.begin(), path_flow.end(), 0);
    queue<int> q;
    parent[src] = -2;
    q.push(src);
    path_flow[src] = INF;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (parent[v] == -1 && capacity[u][v] > flow_passed[u][v]) {
                parent[v] = u;
                path_flow[v] = min(path_flow[u], capacity[u][v] - flow_passed[u][v]);

                if (v == sink)
                    return true;
                q.push(v);
            }
        }
    }
    return false;
}

int max_flow(int src, int sink) {
    int maxFlow = 0;
    while (find_path(src, sink)) {
        int flow = path_flow[sink];
        maxFlow += flow;

        int v = sink;
        while (v != src) {
            int u = parent[v];
            flow_passed[u][v] += flow;
            flow_passed[v][u] -= flow;
            v = u;
        }
    }
    return maxFlow;
}
