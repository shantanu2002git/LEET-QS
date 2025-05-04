class Solution {
public:
    int call(int l, int n) {
        if (n == 0) {
            return 0;
        }
        if (l * l > n || n < 0) {
            return 1e9;
        }
        int tt, nn;
        if (l * l <= n) {
            tt = 1 + call(l, n - (l * l));
        }
        nn = call(l + 1, n);
        return min(tt, nn);
    }
    int numSquares(int n) {

        // return call(1, n);

        vector<int>dp(n + 1, INT_MAX);
        dp[0] = 0;
        vector<int> sqqr;
        for(int it=1; it*it<=n; it++){
            sqqr.push_back(it*it);
        }


        for (int i = 1; i <= n; i++) {
            for (int sq : sqqr) {
                if (sq > i)
                    break;
                dp[i] = min(dp[i], 1 + dp[i - sq]);
            }
        }
        
        return dp[n];
    }
};