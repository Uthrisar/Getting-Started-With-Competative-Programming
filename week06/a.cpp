/*
    Author : Uthrisar Kh. Boro
    Date : 05-09-2024
*/

#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

const int INF = 1e9+5;

vector<pi> g[1001];
int dist[1001];

int dijkstra(int src, int dest){
    dist[src] = 0;
    set<pi> pq;
    pq.insert({0,src});
    while(!pq.empty()){
        auto pr = *pq.begin();
        int d = pr.first;
        int u = pr.second;
        pq.erase(pq.begin());
        for(auto pr2 : g[u]){
            int v = pr2.first;
            int wt = pr2.second;
            if(dist[v] > d+wt){
                dist[v] = d+wt;
                pq.insert({dist[v],v});
            }
        }
    }
    return (dist[dest] == INF) ? -1 : dist[dest];
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }
    cout << dijkstra(1,n);
}
