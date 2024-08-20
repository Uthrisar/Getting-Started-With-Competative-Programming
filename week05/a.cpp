/* Author : Uthrisar Kh. Boro
	Date : 20-8-2024
*/

#include<bits/stdc++.h>
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
using namespace std;

vector<int> graph[101];

int par[101];

int dist[101];

void bfs(int src, int dest){
	set<pair<int,int>> s;
	dist[src] = 0;
	par[src] = -1;
	s.insert({0,src});
	while(!s.empty()){
		auto it = s.begin();
		int d = it->ff;
		int p = it->ss;
		s.erase(it);
		for(auto &child : graph[p]){
            if(dist[child] > 1+d){
                par[child] = p;
                dist[child] = 1+d;
			    s.insert({1+d,child});
            }
		}
	}

	int nd = dest;
	vector<int> ans;
	if(dist[nd] != int(1e9)){
        while(nd != -1){
            ans.push_back(nd);
            nd = par[nd];
        }
        reverse(all(ans));
    }

    if(ans.size() == 0){
        cout << -1;
    } else {
        for(int i = 0; i < int(ans.size()); i++){
            cout << ans[i];
            if(i != int(ans.size())-1){
            	cout <<" ";
            }
        }
    }
}

void solve(){
	int n, a;
	cin >> n >> a;
	while(a--){
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i = 1; i <= 100; i++){
		dist[i] = int(1e9);
		par[i] = 0;
	}
	bfs(1,n);
	for(int i = 1; i <= 100; i++){
		graph[i].clear();
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
		if(t != 0){
			cout << endl;
		}
	}
}