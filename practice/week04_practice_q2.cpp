#include<bits/stdc++.h>
using namespace std;

int par[201];
int sz[201];

void make(int v){
    par[v] = v;
    sz[v] = 1;
}

int find(int v){
    if(par[v] == v) return v;
    return par[v] = find(par[v]);
}

void Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u != v){
        if(sz[u] < sz[v]) swap(u,v);
        par[v] = u;
        sz[u] += sz[v];
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1; i<=n; i++) make(i);
        vector<int> a(n);
        for(auto &x : a){
            cin>>x;
        }
        for(int i=1; i<=n; i++){
            Union(i,a[i-1]);
        }
        for(int i=1; i<=n; i++){
            cout<<sz[find(i)]<<" ";
        }
        if(t != 0) cout<<endl;
    }
}