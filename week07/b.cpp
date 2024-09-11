/*
Author : Uthrisar Kh. Boro
Date : 11-9-2024
*/

#include<bits/stdc++.h>
#define ff first
#define ss second
#define ll long long
using namespace std;

int sz[101], par[101];

void make(int v){
    par[v] = v;
    sz[v] = 1;
}

int find(int v){
    if(v == par[v]) return v;
    return par[v] = find(par[v]);
}

void Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    if(sz[u] < sz[v])
        swap(u,v);
    sz[u] += sz[v];
    par[v] = u;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 1; i <= m; i++){
            int u,v,wt;
            cin >> u >> v >> wt;
            edges.push_back({wt,{u,v}});
        }
        sort(edges.begin(),edges.end());
        for(int i = 1; i <= n; i++){
            make(i);
        }
        int sum = 0;
        for(int i = 0; i < edges.size(); i++){
            auto tuple = edges[i];
            int wt = tuple.ff;
            int u = tuple.ss.ff;
            int v = tuple.ss.ss;
            if(find(u) == find(v))
                continue;
            Union(u,v);
            sum += wt;
        }
        if(t != 0){
            cout << sum << endl;
        } else {
            cout << sum;
        }
        for(int i = 1; i <= n; i++){
            sz[i] = 0;
            par[i] = 0;
        }
    }
}
