/*
Name : Uthrisar Kh. Boro
Date : 02-10-2024
*/

#include<bits/stdc++.h>
using namespace std;

/*
(1,1)->(N,M)
Number of ways : (N+M-2) choose (N-1)
*/

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        n -= 1;
        m -= 1;
        int mn = min(n,m);
        long long ans = 1;
        for(int r = 1; r<=mn; r++){
            ans *= (n+m+1-r);
            ans /= r;
        }
        cout << ans;
        if(tc != 0) cout << endl;
    }
}