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

bool isPossible(int m, vector<int>& donations, int n, int len){
    int req = 0;
    for(int i = 0; i < len; i++){
       req += ((donations[i]/m)+(donations[i]%m != 0));
      if(req > n) {
        return false;
      }
    }
    return req <= n;
}


void solve(){
    int n, len;
    cin >> n >> len;
    vector<int> donations(len);
    int mx = -1;
    for(int i = 0; i < len; i++){
        cin >> donations[i];
        mx = max(donations[i],mx);
    }
    int lo = 1, hi = mx;
    while(hi-lo > 1){
        int mid = lo+(hi-lo)/2;
        if(isPossible(mid,donations, n, len)){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    if(isPossible(lo, donations, n, len)){
        cout << lo;
    } else {
        cout << hi;
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
        if(i != t){
            cout << endl;
        }
    }
}