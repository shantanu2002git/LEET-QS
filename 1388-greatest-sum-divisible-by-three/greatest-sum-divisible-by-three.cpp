class Solution {
public:
    int call(int i, int s, int n, vector<int>& nums, vector<vector<int>>& memo) {
        if (i == n) {
            if (s == 0) {
                return 0;
            }
            return -1e9;
        }
        
        if (memo[i][s] != -1) {
            return memo[i][s];
        }
        
        int tt = nums[i] + call(i + 1, (s + nums[i]) % 3, n, nums, memo);
        int nn = call(i + 1, s, n, nums, memo);

        return memo[i][s] = max(tt, nn);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(3, -1)); // Memoization table

        return call(0, 0, n, nums, memo);
    }
};
