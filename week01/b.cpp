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
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define mi map<int,int>
#define vv vector<vector<int>>
#define all(v) (v).begin(),(v).end()
#define sumAll(v) accumulate(all(v),0)
#define maxHeap priority_queue<int>
#define minHeap priority_queue<int,vector<int>,greater<int>>

using namespace std;

const int mxN = 2e5+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

void solve(){
	int n;
    cin >> n;
    vector<int> H(n);
    for(int i = 0; i < n; i++){
        cin >> H[i];
    }
    bool isIncreasing = 1, isDecreasing = 1;
    for(int i = 1; i < n; i++){
        isIncreasing = isIncreasing && (H[i] >= H[i-1]);
        isDecreasing = isDecreasing && (H[i] <= H[i-1]);
    }
    if(isIncreasing){
        cout << "L";
        return;
    }
    if(isDecreasing){
        cout << "R";
        return;
    }
    cout << "N";
}

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
		if(i != t){
			cout << endl;
		}
	}
}