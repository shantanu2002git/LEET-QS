class Solution {
public:
    int call(int idx, int n, int k, vector<int>& arr, vector<int>& dp) {
        if (idx == n) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int mx = 0, sum = 0, len = 0;
        for (int i = idx; i < min(idx + k, n); i++) {
            len++;
            mx = max(mx, arr[i]);
            sum = mx * len + call(i + 1, n, k, arr, dp);
            dp[idx] = max(dp[idx], sum);
        }
        return dp[idx];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return call(0, n, k, arr, dp);
    }
};
