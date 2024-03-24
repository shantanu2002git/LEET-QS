class Solution {
public:
    int minOperations(int k) {
        if (k == 1)
            return 0;
        int ans = k;
        for (int i = 1; i <= k / 2; ++i) {
            int t = (ceil((double)k / (double)i) - 1) + (i - 1);
            ans = min(ans, t);
        }
        return ans;
    }
};