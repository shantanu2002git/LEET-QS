
class Solution {
public:
    int solve(vector<int> &nums, int ind, int prev, vector<vector<int>> &dp){
        if( ind == nums.size()) return 0;
        
        if( dp[ind][prev+1] != -1) return dp[ind][prev+1]; 
        
        if( prev ==-1 ||  nums[prev] < nums[ind]){
    return dp[ind][prev+1]= max( 1+ solve(nums,ind+1, ind, dp), solve( nums, ind+1, prev, dp));
        }
        
        else{
            return dp[ind][prev+1]=  solve(nums, ind+1, prev, dp);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size()+1, -1));
        return solve( nums, 0, -1, dp);
    }
		
		
};