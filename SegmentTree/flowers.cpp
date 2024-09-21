/*
https://atcoder.jp/contests/dp/tasks/dp_q
Author : Uthrisar Kh. Boro
Date : 21-09-24
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e6+1;

int a[MAXN];
ll seg[4*MAXN];

void update(int k, ll x, int idx, int lo, int hi){
    if(lo==hi){
        seg[idx] = x;
        return;
    }
    int mid=(lo+hi)/2;
    if(k <= mid)
        update(k,x,2*idx,lo,mid);
    else
        update(k,x,2*idx+1,mid+1,hi);

    seg[idx] = max(seg[2*idx],seg[2*idx+1]);
}

ll query(int l, int r, int idx, int lo, int hi){
    if(r < lo || l > hi) return 0;
    if(l <= lo && hi <= r) return seg[idx];
    int mid = (lo+hi)/2;
    ll left = query(l,r,2*idx,lo,mid);
    ll right = query(l,r,2*idx+1,mid+1,hi);
    return max(left,right);
}

int main(){
    int N;
    cin >> N;
    vector<int> h(N+1);
    for(int i=1; i<=N; i++){
        cin >> h[i];
    }
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }
    memset(seg,0,sizeof(seg));
    vector<ll> dp(N+1,0);

    // dp[h[i]] = a[i]+max(dp[1],dp[2],dp[3],.......,dp[h[i]-1])

    for(int i=1; i<=N; i++){
        ll q = 0;  // This will store the maximum beauty sum of smaller heights
        if(h[i]>1){
            q = query(1,h[i]-1,1,1,N);  // Only query when h[i] > 1
        }
        dp[h[i]] = max(dp[h[i]],a[i]+q);  // Update dp for the current height
        update(h[i],dp[h[i]],1,1,N);  // Update the segment tree with the new dp value
    }

    ll ans=0;
    for(int i=1; i<=N; i++){
        ans = max(ans,dp[i]);
    }
    cout << ans;
}