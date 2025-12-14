class Solution {
public:
    bool call(int idx, int n, int s, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (idx == n - 1) {
            return s == nums[idx];
        }
        if (s == 0) {
            return 1;
        }
     
        int nn = 0, tt = 0;
        if (dp[idx][s] != -1) {
            return dp[idx][s];
        }
        if (nums[idx] <= s) {
            tt = call(idx + 1, n, s - nums[idx], nums, dp);
        }
        nn = call(idx + 1, n, s, nums, dp);
        return dp[idx][s] = tt || nn;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return 0;
        }
        int target = sum /2, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return call(0, n, target, nums, dp);
    }
};