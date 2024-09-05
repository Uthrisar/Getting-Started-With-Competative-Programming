/*
    Author : Uthrisar Kh. Boro
    Date : 05-09-2024
*/

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+10;
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n,m,cutoff;
        cin >> n >> m >> cutoff;
        vector<vector<int>> dist(n,vector<int>(n,INF));
        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }
        for(int i = 0; i < m; i++){
            int u,v,t;
            cin >> u >> v >> t;
            dist[u][v] = t;
            dist[v][u] = t;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vector<int> tot(n,0);
        vector<int> conn(n,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && dist[i][j] <= cutoff){
                    conn[i]++;
                    tot[i] += dist[i][j];
                }
            }
        }
        int mn = INF;
        int node = -1;
        int curr_conn = 0;
        for(int i = 0; i < n; i++){
            if(curr_conn < conn[i]){
                curr_conn = conn[i];
                node = i;
                mn = tot[i];
            } else if(curr_conn == conn[i]){
                if(mn > tot[i]){
                    mn = tot[i];
                    node = i;
                } else if(mn == tot[i]){
                    node = i;
                }
            }
        }
        if(tt != 0){
            cout << node << endl;
        } else {
            cout << node;
        }
    }
}
