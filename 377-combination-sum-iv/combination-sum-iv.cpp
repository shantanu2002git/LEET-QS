class Solution {
public:
    int noOfWays(vector<int> &nums, int target, int size, vector<int> &dp)
    {
        if(target < 0) return 0; 
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target]; 
        
        int ways = 0;  
        for(int i = 0; i<size; i++)
        {
            ways += noOfWays(nums, target - nums[i], size, dp);
        }
        dp[target] = ways; 
        return ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp (target+1, -1); 
        return noOfWays(nums, target, nums.size(), dp);
    }
};