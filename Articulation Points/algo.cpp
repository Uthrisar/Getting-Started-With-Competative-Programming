#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int timer = 1;
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool> vis(V,false);
        vector<int> disc(V), low(V), ans;
        dfs(0,-1,vis,adj,disc,low,ans);
        if(ans.size() == 0) ans.push_back(-1);
        set<int> s;
        for(auto node : ans){
            s.insert(node);
        }
        ans.clear();
        for(auto node : s){
            ans.push_back(node);
        }
        return ans;
    }

    void dfs(int v, int par, vector<bool>& vis, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<int>& ans){
        vis[v] = 1;
        disc[v] = low[v] = timer++;
        int countChild=0;
        for(int child : adj[v]){
            if(child == par) continue;
            if(!vis[child]){
                dfs(child,v,vis,adj,disc,low,ans);
                low[v] = min(low[v],low[child]);
                if(par != -1 && low[child] >= disc[v]){
                    ans.push_back(v);
                }
                countChild++;
            } else {
                low[v] = min(low[v],disc[child]);
            }
        }
        if(par == -1 && countChild > 1){
            ans.push_back(0);
        }
    }
};

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> Graph[N];
    for(int i=0; i<M; i++){
        int u,v;
        cin>>u>>v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    Solution sol;
    vector<int> ans = sol.articulationPoints(N,Graph);
    for(auto node : ans){
        cout << node <<" ";
    }
}
