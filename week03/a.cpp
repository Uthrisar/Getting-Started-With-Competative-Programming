#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<cmath>
#include<cstring>
#include<algorithm>

#define endl '\n'
#define ff first
#define ss second
#define ll long long
#define pi pair<int,int>
#define vi vector<int>
#define mi map<int,int>
#define vvi vector<vector<int>>
#define all(v) (v).begin(),(v).end()
#define sumAll(v) accumulate(all(v),0)
#define maxHeap priority_queue<int>
#define minHeap priority_queue<int,vector<int>,greater<int>>

using namespace std;

const int mxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

void solve(){
	int x, h;
	cin >> x >> h;
	vector<ll> C(x);
	for(int i = 0; i < x; i++){
		cin >> C[i];
	}
	ll mn1 = 1e16, mn2 = 1e16;
	for(int i = 0; i < x; i++){
		if(mn1 >= C[i]){
			mn2 = mn1;
			mn1 = C[i];
		} else if(mn2 > C[i]){
			mn2 = C[i];
		}
	}
	ll ans = h;
	ll busy_time = mn1+mn2;
	if(ans >= busy_time){
		ans = ans-busy_time;
	}
	cout << ans;
}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		solve();
		if(i != t){
			cout << endl;
		}
	}
}