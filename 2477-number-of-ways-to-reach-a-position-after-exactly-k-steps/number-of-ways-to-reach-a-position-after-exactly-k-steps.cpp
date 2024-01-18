#include <cstring>
/*
Time Complexity :- O(Start * K)
Space Complexity :- O(Start * K)
*/
class Solution {
public:
    int dp[5001][1001];
    long long mod = 1e9 + 7;

    int call_dp(int start, int end, int k) {
        if (k == 0 && start==end) {
           return 1;
        }else if(k==0){
            return 0;
        }


        if (dp[start + 1000][k] != -1) {
            return dp[start + 1000][k];
        }

        long long lef = (call_dp(start - 1, end, k - 1) % mod) % mod; // left
        long long rig = (call_dp(start + 1, end, k - 1) % mod) % mod; // right

        return dp[start + 1000][k] = (lef + rig) % mod;
    }

    int numberOfWays(int start, int end, int k) {
        memset(dp, -1, sizeof(dp)); 
        return call_dp(start, end, k);
    }
};
