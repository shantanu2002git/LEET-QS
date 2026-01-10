class Solution {
public:
int dp[1007][1007];
    int call(string &s1, string &s2, int i, int j) {
        if (i < 0 && j < 0)
            return 0;
        if (i < 0) {
            return (int)s2[j] + call(s1, s2, i, j - 1);
        }
        if (j < 0) {
            return (int)s1[i] + call(s1, s2, i - 1, j);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ship_i = 0, ship_j = 0;
        if (s1[i] == s2[j])
            return dp[i][j]=call(s1, s2, i - 1, j - 1);
        else
            ship_i = s1[i] + call(s1, s2, i - 1, j);
            ship_j = s2[j] + call(s1, s2, i, j - 1);

        return dp[i][j]=min(ship_i, ship_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        memset(dp,-1, sizeof(dp));
        return call(s1, s2, n - 1, m - 1);
    }
};