/*
Kosaraju Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 5001;

vector<bool> vis(N);

vector<int> graph[N], rGraph[N];

vector<int> finish;

vector<int> component;

vector<vector<int>> scc;

void dfs(int v){
    vis[v] = true;
    for(auto child : graph[v]){
        if(vis[child]) continue;
        dfs(child);
    }
    finish.push_back(v);
}

void find_comp(int v){
    vis[v] = true;
    component.push_back(v);
    for(auto child : rGraph[v]){
        if(vis[child]) continue;
        find_comp(child);
    }
}

int main(){
    int n,e;
    cin >> n >> e;

    // Input graph
    for(int i=0; i<e; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        rGraph[v].push_back(u);
    }

    // First DFS to get finish order
    fill(vis.begin(),vis.end(),false);
    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        dfs(i);
    }

    // Second DFS to find SCCs
    fill(vis.begin(),vis.end(),false);
    reverse(finish.begin(),finish.end());

    for(auto node : finish){
        if(vis[node]) continue;
        component.clear();
        find_comp(node);
        scc.push_back(component);
    }

    // Output the number of SCCs
    cout << "Number of SCCs: " << scc.size() << endl;

    // Output each SCC and its nodes in the correct order
    for(int i = 0; i < scc.size(); i++){
        cout << "SCC #" << i+1 << " (Size: " << scc[i].size() << "): ";
        for(int node : scc[i]){
            cout << node << " ";
        }
        cout << endl;
    }
}
