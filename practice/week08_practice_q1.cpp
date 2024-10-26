#include <bits/stdc++.h>
using namespace std;

// BFS function to find if there is a path from source to sink
bool bfs(vector<vector<int>>& graph, int source, int sink, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1); // Initialize parent array
    vector<bool> visited(26, false);
    visited[source] = true;

    queue<int> q;
    q.push(source);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < 26; v++) {
            if (!visited[v] && graph[u][v] > 0) { // Check for unvisited nodes with positive capacity
                visited[v] = true;
                parent[v] = u;
                if (v == sink) return true; // Path found
                q.push(v);
            }
        }
    }
    return false; // No path found
}

// Ford-Fulkerson algorithm for maximum flow
int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    vector<int> parent(26); // Stores path from source to sink
    int max_flow = 0;

    // Augment the flow while there is a path from source to sink
    while(bfs(graph, source, sink, parent)) {
        int path_flow = INT_MAX;

        // Find the maximum flow through the path found by BFS
        for(int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }

        // Update residual capacities of the edges and reverse edges
        for(int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int e; // Number of edges
    cin >> e;

    vector<vector<int>> graph(26, vector<int>(26, 0));
    for(int i = 0; i < e; i++) {
        char a, b;
        int w;
        cin >> a >> b >> w;
        graph[a - 'A'][b - 'A'] = w;
    }

    // Calculate maximum flow from 'S' (source) to 'T' (sink)
    cout << fordFulkerson(graph, 'S' - 'A', 'T' - 'A');

    return 0;
}
