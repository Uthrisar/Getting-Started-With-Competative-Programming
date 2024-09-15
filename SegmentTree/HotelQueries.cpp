/*
https://cses.fi/problemset/task/1143
Author: Uthrisar Kh. Boro
Date: 15-09-2024
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[200001], ans[200001];
int seg[4*200001];

void build(int ind = 1, int lo = 1, int hi = n){
    if(lo == hi) {
        seg[ind] = a[lo];
        return;
    }
    int mid = (lo+hi)/2;
    build(2*ind,lo,mid);
    build(2*ind+1,mid+1,hi);
    seg[ind] = max(seg[2*ind],seg[2*ind+1]);
}

void update(int i, int u, int ind = 1, int lo = 1, int hi = n){
    if(lo == hi){
        if(u <= seg[ind]){
            seg[ind] -= u;
            ans[i] = lo;
        }
        return;
    }
    int mid = (lo+hi)/2;
    if(u <= seg[2*ind])
        update(i,u,2*ind,lo,mid);
    else if(u <= seg[2*ind+1])
        update(i,u,2*ind+1,mid+1,hi);
    else return;
    seg[ind] = max(seg[2*ind],seg[2*ind+1]);
}

int main(){
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build();
    for(int i = 1; i <= m; i++){
        int r;
        cin >> r;
        update(i,r);
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] <<" ";
    }
}
