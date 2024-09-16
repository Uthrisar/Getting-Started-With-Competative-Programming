#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x: v) cin >> x;

    int l = 0, r = 0;
    multiset<int> mnHeap;
    multiset<int, greater<int>> mxHeap;
    vector<int> ans;

    auto balance = [&]() {
        if(mxHeap.size() > mnHeap.size() + 1) {
            mnHeap.insert(*mxHeap.begin());
            mxHeap.erase(mxHeap.begin());
        } else if(mnHeap.size() > mxHeap.size()) {
            mxHeap.insert(*mnHeap.begin());
            mnHeap.erase(mnHeap.begin());
        }
    };
    while(r < n){
        if(mxHeap.empty() || v[r] <= *mxHeap.begin()){
            mxHeap.insert(v[r]);
        } else {
            mnHeap.insert(v[r]);
        }
        balance();
        if(r-l+1 > k){
            if(mxHeap.find(v[l]) != mxHeap.end()){
                mxHeap.erase(mxHeap.find(v[l]));
            } else {
                mnHeap.erase(mnHeap.find(v[l]));
            }
            l++;
            balance();
        }
        if(r-l+1 == k){
            // if(k&1){
            ans.push_back(*mxHeap.begin());
            // } 
            // else {
            //     ans.push_back((*mxHeap.begin() + *mnHeap.begin()) / 2);
            // }
        }
        r++;
    }

    for(int i=0; i<int(ans.size()); i++){
        cout << ans[i] << " ";
    }
}
