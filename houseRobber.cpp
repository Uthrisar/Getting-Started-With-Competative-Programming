/*
Authro : Uthrisar Kh. Boro
Date : 2-10-2024
*/

/*
House robber profit maximization
using fibonanci recusion
*/

#include<bits/stdc++.h>
using namespace std;

int dp[100005];

int rec(int i, int n, vector<int>& energy){
    if(i > n) return 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] = max(energy[i]+rec(i+2,n,energy),rec(i+1,n,energy));
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int> energy(n);
        for(int i=0; i<n; i++){
            cin>>energy[i];
        }
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,n-2,energy);
        memset(dp,-1,sizeof(dp));
        ans = max(ans,rec(1,n-1,energy));
        cout<<ans;
        if(tc != 0) cout<<endl;
    }
}