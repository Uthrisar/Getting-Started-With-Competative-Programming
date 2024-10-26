#include <bits/stdc++.h>
using namespace std;

long long maxPoints(const vector<int>& a) {
    if (a.empty()) return 0;
    
    int max_val = *max_element(a.begin(), a.end());
    vector<long long> frequency(max_val + 1, 0);
    
    for (int num : a) {
        frequency[num]++;
    }

    vector<long long> dp(max_val + 1, 0);
    
    dp[1] = frequency[1];
  
    for (int i = 2; i <= max_val; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * frequency[i]);
    }

    return dp[max_val];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << maxPoints(a);
    return 0;
}
