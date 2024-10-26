#include <bits/stdc++.h>
#define ii pair<int,int>
#define lgi pair<long,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define vvii vector<vii>
using namespace std;

int find(int u, vi& p) {
    if (u == p[u]) return u;
    return p[u] = find(p[u], p);
}

bool iSameSet(int u, int v, vi& p) {
    return find(u, p) == find(v, p);
}

void unionSet(int i, int j, vi& p, vi& setsz, vi& rank) {
    int x = find(i, p), y = find(j, p);
    if (x == y) return;
    if (rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y]) rank[y]++;
    setsz[y] += setsz[x];
}

int Kruskal(int n, int m, vvi& edges) {
    sort(edges.begin(), edges.end(), [](const vi& v1, const vi& v2) {
        return v1[0] < v2[0];  // Sort by edge weight in ascending order
    });

    int u, v, w, mstcost = 0;
    vi p(n), setsz(n, 1), rank(n);

    for (int i = 0; i < n; i++) p[i] = i;

    for (int i = 0; i < edges.size(); i++) {
        w = edges[i][0];
        u = edges[i][1];
        v = edges[i][2];

        if (iSameSet(u, v, p)) continue;

        unionSet(u, v, p, setsz, rank);
        mstcost += w;  // Directly add the weight, no negation needed
    }

    return mstcost;
}

int main() {
    int n, m, u, v, w, totalEdgeCost = 0;
    cin >> n >> m;

    vvi edges;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--; v--;

        edges.push_back({w, u, v});
        totalEdgeCost += w;
    }

    cout << (totalEdgeCost - Kruskal(n, m, edges));
}