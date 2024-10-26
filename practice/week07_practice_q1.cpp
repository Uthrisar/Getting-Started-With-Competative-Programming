#include <bits/stdc++.h>
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define lg long
#define lgi pair<lg, int>
using namespace std;

long MST(int n, int m, vvii &graph)
{

    vi taken(n);

    priority_queue<lgi> pq;

    int u, v, w;
    long cost = 0;

    for (auto &e : graph[0])
    {
        v = e.first;
        w = e.second;
        pq.push({-w, v});
    }

    taken[0] = 1;

    while (!pq.empty())
    {
        u = pq.top().second;
        w = -pq.top().first;
        pq.pop();

        if (taken[u])
            continue;
        cost += w;
        taken[u] = 1;

        for (auto &e : graph[u])
        {
            v = e.first;
            w = e.second;
            pq.push({-w, v});
        }
    }

    return cost;
}

int main()
{

    int tt, n, m, u, v, w;
    cin >> tt;

    while (tt--)
    {
        cin >> n >> m;

        vvii graph(n);

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            u--;
            v--;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        cout << MST(n, m, graph);

        if (tt >= 1)
            cout << endl;
    }
}