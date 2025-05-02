class Solution {
public:
int mod=1e9+7;
    int countOrders(int n) {
        if (n == 1) {
            return 1;
        }

        int comres = 1;
        for (int i = 2; i <= n; i++) {
           long long space = (2 * i - 1);
            long long combinations = (space * (space + 1)) / 2; // Calculate combinations
            comres = (comres * combinations) % mod; // Apply mod after each multiplication
        }
        return comres%mod;
    }
};