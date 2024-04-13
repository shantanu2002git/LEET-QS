class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int prv = 0; prv < i; prv++) {
                if (nums[prv] < nums[i]) {
                    if (1 + dp[prv] > dp[i]) {
                        dp[i] = 1 + dp[prv];
                        cnt[i] = cnt[prv];
                    } else if (1 + dp[prv] == dp[i]) {
                        cnt[i] += cnt[prv];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int nps = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi) {
                nps += cnt[i];
            }
        }
        return nps;
    }
};
