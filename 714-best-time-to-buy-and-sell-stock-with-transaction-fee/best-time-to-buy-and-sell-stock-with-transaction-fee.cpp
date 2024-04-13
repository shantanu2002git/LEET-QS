class Solution {
public:
    int call(int i, int n, int by, int fe, vector<int>& p,
             vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][by] != -1) {
            return dp[i][by];
        }
        int prft = 0;
        if (by) {
            prft = max(-(p[i] + fe) + call(i + 1, n, 0, fe, p, dp),
                       0 + call(i + 1, n, 1, fe, p, dp));
        } else {
            prft = max(+p[i] + call(i + 1, n, 1, fe, p, dp),
                       0 + call(i + 1, n, 0, fe, p, dp));
        }
        return dp[i][by] = prft;
    }
    int maxProfit(vector<int>& p, int fe) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return call(0, n, 1, fe, p, dp);
    }
};