class Solution {
public:
    const int md = 1e9 + 7;
    
    int numTilings(int n) {
        if (n <= 2) return n;
        
        vector<long long> dp(n + 1); // Use long long to prevent overflow
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % md;
        }
        
        return dp[n];
    }
};