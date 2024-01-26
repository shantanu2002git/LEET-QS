#include <vector>
using namespace std;

class Solution {
public:
    int changeUtil(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp) {
       
        if (amount == 0) return 1;  
        if (amount < 0 || idx < 0) return 0;  

        if (dp[idx][amount] != -1) return dp[idx][amount];

        int waysWithCoin = changeUtil(idx, amount - coins[idx], coins, dp);
        int waysWithoutCoin = changeUtil(idx - 1, amount, coins, dp);

        return dp[idx][amount] = waysWithCoin + waysWithoutCoin;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
       
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return changeUtil(n - 1, amount, coins, dp);
    }
};
