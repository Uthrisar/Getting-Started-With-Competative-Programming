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
    int n;
    cin >> n;
    vector<int> b_s(n);
    for(int i = 0; i < n; i++){
      cin >> b_s[i];
    }

    vector<int> bs_copy = b_s;
    sort(all(bs_copy));

    int mx = 0, currMax = -1;

    for(int i = 0; i < n; i++){
      currMax = max(currMax, b_s[i]);
      if(currMax == bs_copy[i]){
        mx++;
        currMax = -1;
      }
    }
    cout << mx;
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