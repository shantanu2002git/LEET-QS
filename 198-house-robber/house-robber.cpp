
class Solution {
public:
    int n;

    int call(vector<int>& nums, int idx ,vector<int>&dp) {
        if (idx == 0) {
            return nums[idx];
        } else if (idx < 0) {
            return 0;
        }
if(dp[idx]!=-1){
    return dp[idx];
}
        int ttk, ntt;
            ttk =nums[idx]+call(nums, idx - 2,dp);
        ntt = 0+call(nums, idx-1,dp);
     
        

        return dp[idx]=max(ntt, ttk);
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int>dp(n+1,-1);
        
        return call(nums, n - 1, dp);
    }
};
