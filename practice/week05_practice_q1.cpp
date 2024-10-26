#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int computeDepth(int node, vector<int> &parent, vector<int> &depth)
{
    if (depth[node] != -1)
    {
        return depth[node];
    }
    if (parent[node] == -1)
    {
        return depth[node] = 1;
    }
    return depth[node] = computeDepth(parent[node], parent, depth) + 1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<int> depth(n + 1, -1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> parent[i];
    }

    int maxDepth = 0;
    // Calculate the depth for each node
    for (int i = 1; i <= n; ++i)
    {
        maxDepth = max(maxDepth, computeDepth(i, parent, depth));
    }

    cout << maxDepth;
    return 0;
}