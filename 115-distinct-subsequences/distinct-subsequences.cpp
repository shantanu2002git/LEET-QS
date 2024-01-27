class Solution {
public:
    int call(int idx1, int idx2, string s, string t, vector<vector<int>>& dp) {
        if (idx2 < 0) {
            return 1;
        }
        if (idx1 < 0) {
            return 0;
        }
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        if (s[idx1] == t[idx2]) {
            return dp[idx1][idx2] = call(idx1 - 1, idx2 - 1, s, t, dp) + call(idx1 - 1, idx2, s, t, dp);
        } else {
            return dp[idx1][idx2] = call(idx1 - 1, idx2, s, t, dp);
        }
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return call(n - 1, m - 1, s, t, dp);
    }
};
