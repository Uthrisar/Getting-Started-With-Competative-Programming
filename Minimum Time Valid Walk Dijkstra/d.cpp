#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int MAXN = 2001;
typedef pair<int, int> pii;

vector<pii> adj[MAXN], rev_adj[MAXN];
int dist[MAXN], rev_dist[MAXN];

void dijkstra(int src, vector<pii> adj[], int dist[]) {
    fill(dist,dist+MAXN,INF);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(const auto& [v, weight] : adj[u]) {
            if(dist[u]+weight < dist[v]) {
                dist[v] = dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        rev_adj[b].push_back({a, c});
    }
    for(int src = 1; src <= N; src++) {
        dijkstra(src, adj, dist);
        dijkstra(src, rev_adj, rev_dist);
        int min_cycle_time = INF;
        for(int v = 1; v <= N; v++) {
            if(src != v && dist[v] < INF && rev_dist[v] < INF) {
                min_cycle_time = min(min_cycle_time,dist[v]+rev_dist[v]);
            }
        }
        for(const auto& [v, weight] : adj[src]) {
            if(v == src) {
                min_cycle_time = min(min_cycle_time,weight);
            }
        }
        if(min_cycle_time == INF) {
            cout << -1 << endl;
        } else {
            cout << min_cycle_time << endl;
        }
    }
}
