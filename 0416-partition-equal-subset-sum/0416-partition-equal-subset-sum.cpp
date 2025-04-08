class Solution {
public:
    bool call(int idx, int n, int s, vector<int>& nums) {
        if (idx >= n) {
            return (s == 0);
        }

        int tt = 0, nn = 0;

        if (s >= nums[idx]) {
            tt = call(idx + 1, n, s - nums[idx], nums);
        }
        nn = call(idx + 1, n, s, nums);

        return (tt || nn);
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) {
            return 0;
        }
        int targetSum = total / 2;
        int n = nums.size();

        // return call(0, n, targetSum, nums);

        vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= targetSum; j++) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][targetSum];
    }
};