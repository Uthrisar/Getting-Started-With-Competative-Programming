#include <bits/stdc++.h>
using namespace std;

class DAGPathCover
{
public:
    DAGPathCover(int n) : n(n), adj(n), match(n, -1), visited(n, false) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool dfs(int u)
    {
        if (visited[u])
            return false;
        visited[u] = true;

        for (int v : adj[u])
        {
            if (match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int maximumMatching()
    {
        int maxMatching = 0;

        for (int u = 0; u < n; u++)
        {
            fill(visited.begin(), visited.end(), false);
            if (dfs(u))
            {
                maxMatching++;
            }
        }
        return maxMatching;
    }

    bool hasDisjointPathCoverAtMostK(int k)
    {
        int maxMatching = maximumMatching();
        int minPathCover = n - maxMatching;
        return minPathCover <= k;
    }

private:
    int n;
    vector<vector<int>> adj;
    vector<int> match;
    vector<bool> visited;
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    DAGPathCover dag(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--; // Assuming 1-based input
        dag.addEdge(u, v);
    }

    cout << (dag.hasDisjointPathCoverAtMostK(k) ? "YES" : "NO");

    return 0;
}
