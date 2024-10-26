#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> H(2*n);
        for(int i=0; i<2*n; i++){
            cin>>H[i];
        }
        sort(H.begin(),H.end());
        bool ans = true;
        for(int i=0; i<n; i++){
            if(H[i]+x > H[n+i]){
                ans = false;
                break;
            }
        }
        if(ans) cout<<"YES";
        else cout<<"NO";
        if(t != 0) cout<<endl;
    }
}