#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        vector<int> pf_sum(n);
        pf_sum[0] = a[0];
        for(int i=1; i<n; i++){
            pf_sum[i] = pf_sum[i-1]+a[i];
        }
        while(q--){
            int x;
            cin>>x;
            auto it = lower_bound(pf_sum.begin(),pf_sum.end(),x);
            if(it == pf_sum.end()) cout<<-1;
            else{
                int idx = it-pf_sum.begin();
                idx++;
                cout<<idx;
            }
            if(t!=0 || q!=0) cout<<endl;
        }
    }
}