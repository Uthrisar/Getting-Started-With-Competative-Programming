/* Author : Uthrisar Kh. Boro
	Date : 19-8-2024
*/

#include<bits/stdc++.h>
using namespace std;

int par[501];

int sz[501];

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
	if(u != v){
		if(sz[u] < sz[v]){
			swap(u,v);
		}
		par[v] = u;
		sz[u] += sz[v];
	}
}

void reset(){
	for(int i = 1; i <= 500; i++){
		sz[i] = 0;
		par[i] = 0;
	}
}

void solve(){
	int n, tours;
	cin >> n >> tours;
	for(int i = 1; i <= n; i++){
		make(i);
	}
	while(tours--){
		int a, b;
		cin >> a >> b;
		Union(a,b);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(par[i] == i){
			ans++;
		}
	}
	cout << ans;
	reset();
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