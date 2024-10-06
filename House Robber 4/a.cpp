class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int lo = 1, hi = 1e9;
        int ans = INT_MAX;
        while(hi-lo > 1){
            int mid = lo+(hi-lo)/2;
            if(canPossible(mid,k,nums)){
                ans = min(ans,mid);
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        if(canPossible(lo,k,nums)) return min(ans,lo);
        else return min(ans,hi);
    }

    bool canPossible(int mid, int k, vector<int>& nums){
        int i = 0, n = nums.size();
        while(i < n){
            if(nums[i] <= mid){
                k--;
                i += 2;
            } else {
                i++;
            }
            if(k == 0) return true;
        }
        return k == 0;
    }
};
