/*
https://cses.fi/problemset/task/1650
Author: Uthrisar Kh. Boro
Date: 15-09-2024
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
    return seg[idx] = left^right;
}

int query(int a, int b, int idx, int low, int high){
    if(low > b || high < a) return 0;
    if(low >= a && high <= b) return seg[idx];
    int mid = (low+high)/2;
    int left = query(a,b,2*idx,low,mid);
    int right = query(a,b,2*idx+1,mid+1,high);
    return left^right;
}

int main(){
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << query(a,b,1,1,n) << endl;
    }
}
