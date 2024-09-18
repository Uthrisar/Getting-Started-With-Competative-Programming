#include<bits/stdc++.h>

#define N 501 // maximum no. of nodes in graph
#define INF 2147483646

using namespace std;

int capacity[N][N];
int flowPassed[N][N];
int path_flow[N];
vector<int> graph[N];

int parent[N];

bool bfs(int s, int t) {
    fill(parent, parent + N, -1); // Reset parents for each test
    fill(path_flow, path_flow + N, 0); // Reset path flow for each test

    queue<int> q;
    parent[s] = -2;
    q.push(s);
    path_flow[s] = INF; // Start with infinite flow

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : graph[u]) {
            if(parent[v] == -1 && capacity[u][v] - flowPassed[u][v] > 0) {
                parent[v] = u;
                path_flow[v] = min(path_flow[u], capacity[u][v] - flowPassed[u][v]);
                if(v == t) return true; // If sink is reached
                q.push(v);
            }
        }
    }
    return false; // No path found
}

// Max-flow implementation using Edmonds-Karp (BFS-based Ford-Fulkerson)
int max_flow(int source, int sink) {
    int maxFlow = 0;

    while(bfs(source, sink)) {
        int flow = path_flow[sink];
        maxFlow += flow;

        // Traverse the path backwards from sink to source and update flows
        int u = sink;
        while(u != source) {
            int v = parent[u];
            flowPassed[v][u] += flow;
            flowPassed[u][v] -= flow; // Residual flow
            u = v;
        }
    }

    return maxFlow;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, e;
        cin >> n >> e;

        // Edge case: If n == 1, source and sink are the same
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }

        // Reset for each test case
        for(int i = 1; i < N; i++) {
            graph[i].clear();
            for(int j = 1; j < N; j++) {
                capacity[i][j] = 0;
                flowPassed[i][j] = 0;
            }
        }

        int s = 1, t = n;  // source and sink
        for(int i = 0; i < e; i++) {
            int from, to, cap = 1;
            cin >> from >> to;
            capacity[from][to] = cap;
            graph[from].push_back(to);
            graph[to].push_back(from); // Residual graph
        }
        int maxFlow = max_flow(s, t);
        cout << maxFlow;
        if(tc!=0){
            cout<<endl;
        }
    }
}
