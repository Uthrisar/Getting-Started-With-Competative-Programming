#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

const int N = 1e5;

int vis[N];
int st[N];
int low[N];
vector<int> graph[N];

int timer=1;

vector<pair<int,int>> bridges;

void dfs(int v, int par){
    vis[v]=1;
    st[v] = low[v] = timer++;
    for(int child : graph[v]){
        if(child == par) continue;
        if(!vis[child]){
            dfs(child,v);
            low[v] = min(low[v],low[child]);
            if(low[child] > st[v]){
                bridges.push_back(make_pair(v,child));
            }
        } else {
            low[v] = min(low[v],low[child]);
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0,-1);
    for(auto &pr : bridges){
        cout << pr.ff << " " << pr.ss << endl;
    }
}