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
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	int sum = 0, mx = 0;
	for(int i = 0; i < n; i++){
		sum += v[i];
		if(sum < 0){
			sum = 0;
		}
		if(mx < sum){
			mx = sum;
		}
	}
	ll ans = mx*1LL*x;
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