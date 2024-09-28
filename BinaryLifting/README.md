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
 
int up[200001][20];
 
int depth[200001];
 
vector<int> g[200001];
 
void dfs(int v, int p=-1){
    up[v][0]=p;
    for(int i=1; i<20; i++){
        if(up[v][i-1] != -1){
            up[v][i]=up[up[v][i-1]][i-1];
        }
    }
    for(int c : g[v]){
        if(c != p){
            depth[c]=1+depth[v];
            dfs(c,v);
        }
    }
}
 
int lift_node(int node, int jump_req){
    for(int jump=19; jump>=0; jump--){
        if(node == -1 || jump_req == 0)
            break;
        if(jump_req >= (1<<jump)){
            node = up[node][jump];
            jump_req -= (1<<jump);
        }
    }
    return node;
}
 
int lca(int a, int b){
    if(depth[a] < depth[b])
        swap(a,b);
    a = lift_node(a,depth[a]-depth[b]);
    if(a==b) return a;
    for(int jump=19; jump>=0; jump--){
        if(up[a][jump] != up[b][jump]){
            a=up[a][jump];
            b=up[b][jump];
        }
    }
    return up[a][0];
}
 
int main(){
    memset(up,-1,sizeof(up));
    int n,q;
    cin>>n>>q;
    for(int e=2; e<=n; e++){
        int x;
        cin >> x;
        g[e].push_back(x);
        g[x].push_back(e);
    }
    dfs(1);
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
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
