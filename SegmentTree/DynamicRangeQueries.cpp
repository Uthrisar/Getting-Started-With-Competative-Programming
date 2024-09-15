/*
Author: Uthrisar
*/

#include<bits/stdc++.h>
using namespace std;

int a[200001];

int seg[4*200001];

int n;

int build(int idx, int low, int high){
    if(low == high) return seg[idx] = a[low];
    int mid = (low+high)/2;
    int left = build(2*idx,low,mid);
    int right = build(2*idx+1,mid+1,high);
    return seg[idx] = min(left,right);
}

void update(int k, int u, int idx, int low, int high){
    if(k < low || k > high) return;
    if(low == high && low == k){
        seg[idx] = u;
        return;
    }
    int mid = (low+high)/2;
    update(k,u,2*idx,low,mid);
    update(k,u,2*idx+1,mid+1,high);
    seg[idx] = min(seg[2*idx],seg[2*idx+1]);
}

int query(int a, int b, int idx, int low, int high){
    if(low > b || high < a) return 1e9;
    if(low >= a && high <= b) return seg[idx];
    int mid = (low+high)/2;
    int left = query(a,b,2*idx,low,mid);
    int right = query(a,b,2*idx+1,mid+1,high);
    return min(left,right);
}

int main(){
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int k,u;
            cin >> k >> u;
            update(k,u,1,1,n);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(a,b,1,1,n) << endl;
        }
    }
}
