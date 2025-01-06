// Divide and Conquer

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5+5;

struct node {
    ll sum, la, ls;
    node(){
        sum = 0;
        la = 0;
        ls = 0;
    }
};

int arr[MAXN];
node lazy[4*MAXN];

void build(int ind, int lo, int hi){
    if(lo == hi){
        lazy[ind].sum = arr[lo];
        return;
    }
    int mid = lo+(hi-lo)/2;
    build(ind<<1, lo, mid);
    build(ind<<1|1, mid+1, hi);
    lazy[ind].sum = lazy[ind<<1].sum+lazy[ind<<1|1].sum;
}

void push_down(int ind, int lo, int hi){
    if(lazy[ind].ls != 0){   // set should be done before add
        lazy[ind].sum = lazy[ind].ls*(hi-lo+1);
        if(lo != hi){
            lazy[ind<<1].ls = lazy[ind].ls;
            lazy[ind<<1|1].ls = lazy[ind].ls;
            lazy[ind<<1].la = 0;
            lazy[ind<<1|1].la = 0;
        }
        lazy[ind].ls = 0;
    }
    if(lazy[ind].la != 0){  // add should be done after set
        lazy[ind].sum += lazy[ind].la*(hi-lo+1);
        if(lo != hi){
            lazy[ind<<1].la += lazy[ind].la;
            lazy[ind<<1|1].la += lazy[ind].la;
        }
        lazy[ind].la = 0;
    }
}

void update_add(int ind, int lo, int hi, int a, int b, int x){
    push_down(ind, lo, hi);
    if(lo > b || hi < a) return;
    if(lo >= a && hi <= b){
        lazy[ind].la += x;
        push_down(ind, lo, hi);
        return;
    }
    int mid = lo+(hi-lo)/2;
    update_add(ind<<1, lo, mid, a, b, x);
    update_add(ind<<1|1, mid+1, hi, a, b, x);
    lazy[ind].sum = lazy[ind<<1].sum+lazy[ind<<1|1].sum;
}
void update_set(int ind, int lo, int hi, int a, int b, int x){
    push_down(ind, lo, hi);
    if(lo > b || hi < a) return;
    if(lo >= a && hi <= b){
        lazy[ind].ls = x;
        lazy[ind].la = 0;
        push_down(ind, lo, hi);
        return;
    }
    int mid = lo+(hi-lo)/2;
    update_set(ind<<1, lo, mid, a, b, x);
    update_set(ind<<1|1, mid+1, hi, a, b, x);
    lazy[ind].sum = lazy[ind<<1].sum+lazy[ind<<1|1].sum;
}

ll query(int ind, int lo, int hi, int a, int b){
    push_down(ind, lo, hi);
    if(lo > b || hi < a){
        return 0;
    }
    if(a <= lo && hi <= b){
        return lazy[ind].sum;
    }
    int mid = lo+(hi-lo)/2;
    ll left = query(ind<<1, lo, mid, a, b);
    ll right = query(ind<<1|1, mid+1, hi, a, b);
    return left+right;
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    build(1, 1, n);
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int a,b,x;
            cin>>a>>b>>x;
            update_add(1, 1, n, a, b, x);
        } else if(type == 2){
            int a,b,x;
            cin>>a>>b>>x;
            update_set(1, 1, n, a, b, x);
        } else {
            int a, b;
            cin>>a>>b;
            cout<<query(1, 1, n, a, b)<<endl;
        }
    }
}