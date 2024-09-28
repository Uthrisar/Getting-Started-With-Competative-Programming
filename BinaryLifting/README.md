# Create a README.md file for Binary Lifting

binary_lifting_readme_content = """
# Binary Lifting

## Introduction
**Binary Lifting** is a technique used for efficiently finding the **Lowest Common Ancestor (LCA)** of two nodes in a tree and for solving various path-related queries. It leverages binary representation to perform ancestor jumps in logarithmic time, making it ideal for trees with large heights.

### Use Cases
1. **Finding the LCA (Lowest Common Ancestor)** of two nodes in `O(log N)` time.
2. **Finding the k-th ancestor** of a node.
3. Solving **path-related queries** such as distance between nodes, path sums, or path maximums.
4. **Efficient tree traversal** and answering range queries on tree paths.

## Binary Lifting Overview
The key idea behind Binary Lifting is to precompute jump pointers for each node to its `2^i`-th ancestor (where `i = 0, 1, 2, ...`). Using these pointers, we can "jump" upwards in the tree in logarithmic steps to reach the desired ancestor.

### Steps:
1. **Precompute Jump Pointers:** Construct a table where `up[v][i]` represents the `2^i`-th ancestor of node `v`.
2. **Use Binary Representation:** Use binary representation of numbers to decide the jumps needed.
3. **Query Efficiently:** For LCA or k-th ancestor queries, perform the jumps in `O(log N)` time using the precomputed table.

## Example Implementation
### Problem Statement
Given a tree with `N` nodes, preprocess the tree for LCA queries. Then, for each query, find the Lowest Common Ancestor of two given nodes.

### Implementation
```cpp
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100001; // Maximum number of nodes
const int LOG = 17;      // log2(MAXN) (ensures we can jump to 2^LOG ancestors)

vector<int> adj[MAXN];  // Adjacency list representation of the tree
int up[MAXN][LOG];      // up[v][j] stores the 2^j-th ancestor of node v
int depth[MAXN];        // Stores depth of each node

// Precompute up table and depth of each node using DFS
void dfs(int v, int parent) {
    up[v][0] = parent; // Immediate parent
    for (int i = 1; i < LOG; i++) {
        if (up[v][i - 1] != -1) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        } else {
            up[v][i] = -1;  // No ancestor exists
        }
    }
    for (int u : adj[v]) {
        if (u != parent) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

// Function to find LCA of nodes u and v
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v); // u should be deeper
    // Lift u up to the same depth as v
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((diff >> i) & 1) {
            u = up[u][i];
        }
    }
    if (u == v) return u;  // Same node is LCA
    // Lift both nodes up until they have the same parent
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];  // Return the parent of u (or v) which is the LCA
}

int main() {
    int N;  // Number of nodes
    cin >> N;

    // Read tree edges
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(up, -1, sizeof(up));  // Initialize up table
    depth[1] = 0;                // Root node depth is 0
    dfs(1, -1);                  // Start DFS from root (1)

    int Q;  // Number of queries
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << "LCA of " << u << " and " << v << " is: " << lca(u, v) << endl;
    }
}
6
1 2
1 3
2 4
2 5
3 6
3
4 5
4 6
5 6
LCA of 4 and 5 is: 2
LCA of 4 and 6 is: 1
LCA of 5 and 6 is: 1
