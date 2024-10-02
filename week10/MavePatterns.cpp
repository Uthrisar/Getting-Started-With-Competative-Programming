/*
Authro : Uthrisar Kh. Boro
Date : 2-10-2024
*/

/*
Mave pattern -> using fibonanci recusion

int rec(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return rec(n-1)+rec(n-2)+2;
}

*/

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e6+1;

int dp[MAXN];

int main(){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<MAXN; i++){
        dp[i] = (2+dp[i-1]+dp[i-2])%MOD;
    }
    int tc;
    cin>>tc;
    while(tc--){
        int N;
        cin>>N;
        cout << dp[N];
        if(tc != 0) cout << endl;
    }
}