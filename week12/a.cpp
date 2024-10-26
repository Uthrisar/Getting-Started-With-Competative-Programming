#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int m,n;
        cin>>m>>n;
        string s,t;
        cin>>s>>t;
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int j=0; j<=n; j++){
            dp[0][j] = 1;
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] %= MOD;
                }
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
        if(tc != 0)
            cout<<dp[m][n]<<endl;
        else
            cout<<dp[m][n];
    }
}