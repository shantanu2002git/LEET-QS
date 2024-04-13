
class Solution {
public:
    int _call(vector<int>& Arr, int n, int ind, int buy, int cap,
               vector<vector<vector<int>>>& dp) {

        if (ind == n || cap == 0)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit;

        if (buy == 0) { // We can buy the stock or not
            profit = max(0 + _call(Arr, n, ind + 1, 0, cap, dp),
                         -Arr[ind] + _call(Arr, n, ind + 1, 1, cap, dp));
        }

        if (buy == 1) { // We can sell the stock or not
            profit = max(0 + _call(Arr, n, ind + 1, 1, cap, dp),
                         Arr[ind] + _call(Arr, n, ind + 1, 0, cap - 1, dp));
        }

        return dp[ind][buy][cap] = profit;
    }
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return _call(p, n, 0, 0, k, dp);
    }
};