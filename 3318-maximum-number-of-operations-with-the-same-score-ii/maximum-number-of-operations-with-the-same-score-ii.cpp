class Solution {
private:
    int func(vector<int>& nums, int i, int j, vector<vector<int>>& dp, int val) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int op1 = 0, op2 = 0, op3 = 0;
        if (i + 1 <= j && nums[i] + nums[i + 1] == val)
            op1 = 1 + func(nums, i + 2, j, dp, val);
        
        if (nums[i] + nums[j] == val)
            op2 = 1 + func(nums, i + 1, j - 1, dp, val);
        
        if (j - 1 >= i && nums[j] + nums[j - 1] == val)
            op3 = 1 + func(nums, i, j - 2, dp, val);
        
        return dp[i][j] = max({op1, op2, op3});
    }
    
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp1(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> dp2(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> dp3(n + 1, vector<int>(n + 1, -1));
        
        int v1 = nums[0] + nums[1];
        int v2 = nums[0] + nums[n - 1];
        int v3 = nums[n - 1] + nums[n - 2];
        
        int ans = 0;
        ans = max(ans, func(nums, 0, n - 1, dp1, v1));
        ans = max(ans, func(nums, 0, n - 1, dp2, v2));
        ans = max(ans, func(nums, 0, n - 1, dp3, v3));
        
        return ans;
    }
};
