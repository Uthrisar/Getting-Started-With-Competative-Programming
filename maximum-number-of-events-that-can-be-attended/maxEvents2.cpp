
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
// Author: Uthrisar Kh. Boro
// Date: 15-09-2024


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        for(int i=0; i<n; i++){
            events[i][0]--;
        }
        sort(events.begin(),events.end(),[&](vector<int> v1, vector<int> v2)->bool{
            return v1[1] < v2[1];
        });
        vector<int> endPoints;
        for(int i=0; i<n; i++){
            endPoints.push_back(events[i][1]);
        }
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return f(n-1,k,endPoints,events,dp);
    }
    int f(int ind,int k,vector<int>& endPoints,vector<vector<int>>& events,vector<vector<int>>& dp){
        if(k == 0) return 0;
        if(ind < 0) return 0;
        if(dp[ind][k] != -1) return dp[ind][k];
        int ans = f(ind-1,k,endPoints,events,dp);
        auto it = upper_bound(endPoints.begin(),endPoints.end(),events[ind][0]);
        if(it != endPoints.begin()){
            it--;
            int j = distance(endPoints.begin(),it);
            ans = max(ans,f(j,k-1,endPoints,events,dp)+events[ind][2]);
        } else {
            ans = max(ans,events[ind][2]);
        }
        return dp[ind][k]=ans;
    };
};

int main(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> events(n,vector<int>(3));
    for(int i=0; i<n; i++){
        cin>>events[i][0]>>events[i][1]>>events[i][2];
    }
    Solution sol;
    cout << sol.maxValue(events,k);
}