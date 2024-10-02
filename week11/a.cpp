/*
Date :- 02-10-2024
*/

/*
concept use :- Longest commong substring
*/


#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int tc;
//     cin>>tc;
//     while(tc--){
//         int n; long long x,s;
//         cin>>n>>x>>s;
//         string a;
//         cin>>a;
//         bool dp[n][n];
//         memset(dp,false,sizeof(dp));
//         for(int i=0; i<n; i++){
//             dp[i][i] = true;
//         }
//         for(int i=0; i<n-1; i++){
//             if(a[i] == a[i+1]){
//                 dp[i][i+1] = true;
//             }
//         }
//         int mx = 0;
//         for(int width = 2; width < n; width++){
//             for(int L = 0; L+width < n; L++){
//                 int R = L+width;
//                 if(a[L] == a[R]){
//                     dp[L][R] = dp[L+1][R-1];
//                     if(dp[L][R]){
//                         mx = max(mx,R-L+1);
//                     }
//                 }
//             }
//         }
//         long long life = mx*s;
//         if(life >= x){
//             cout << 1;
//         } else {
//             cout << 0;
//         }
//         if(tc != 0) cout << endl;
//     }
// }

int lc_substr(string& s){
    int n = s.length();
    int maxLength = 1;
    for(int center = 0; center < n; center++) {
        int l = center, r = center;
        while(l >= 0 && r < n && s[l] == s[r]){
            maxLength = max(maxLength,r-l+1);
            l--;
            r++;
        }
        l = center, r = center+1;
        while(l >= 0 && r < n && s[l] == s[r]){
            maxLength = max(maxLength,r-l+1);
            l--;
            r++;
        }
    }
    return maxLength;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        long long x, s;
        cin >> n >> x >> s;
        string a;
        cin >> a;
        long long maxLength = lc_substr(a);
        maxLength = maxLength*s;

        if(maxLength >= x) cout << 1;
        else cout << 0;

        if(tc != 0) cout << '\n';
    }
}
