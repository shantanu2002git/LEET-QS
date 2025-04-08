class Solution {
public:
    int dp[71][5001];

    int call(int i, int sum, vector<vector<int>>& mat, int target) {
        if (i == mat.size()) {
            return abs(sum - target);
        }
        if (dp[i][sum] != -1) return dp[i][sum];

        int res = INT_MAX;
        for (int val : mat[i]) {
            res = min(res, call(i + 1, sum + val, mat, target));
        }
        return dp[i][sum] = res;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(dp, -1, sizeof(dp));
        return call(0, 0, mat, target);
    }
};
