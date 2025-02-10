#include<bits/stdc++.h>
using namespace std;

const int INF=2e9;

vector<int> par(501);
vector<int> path_flow(501);

vector<int> graph[501];
int flowPassed[501][501];
int capacity[501][501];

bool bfs(int s, int t){
    fill(par.begin(),par.end(),-1);
    fill(path_flow.begin(),path_flow.end(),0);
    queue<int> q;
    par[s]=-2;
    q.push(s);
    path_flow[s]=INF;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : graph[u]){
            if(par[v]==-1 && capacity[u][v]>flowPassed[u][v]){
                par[v]=u;
                path_flow[v] = min(path_flow[u],capacity[u][v]-flowPassed[u][v]);
                if(v == t) return true;
                q.push(v);
            }
        }
    }
    return false; // No path found
}

int max_flow(int src, int sink){
    int maxFlow = 0;
    while(bfs(src,sink)){
        int flow = path_flow[sink];
        maxFlow += flow;
        int u=sink;
        while(u != src){
            int v = par[u];
            flowPassed[u][v] -= flow;
            flowPassed[v][u] += flow;
            u = v;
        }
    }
    return maxFlow;
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        capacity[u][v]=1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s=1, t=n;
    cout<<max_flow(s,t);
}
