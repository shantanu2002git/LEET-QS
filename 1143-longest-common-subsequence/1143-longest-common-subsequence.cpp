class Solution {
public:
    int call(string t1, string t2, int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        long long tt = 0, nn = 0;
        if (t1[i] == t2[j]) {
            return 1 + call(t1, t2, i - 1, j - 1);
        } else {
            return max(call(t1, t2, i - 1, j), call(t1, t2, i, j - 1));
        }

        return (tt, nn);
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.size(), m = t2.size();
        // return call(t1, t2, n - 1, m - 1);
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
       
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--)
            {
                if(t1[i]==t2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};