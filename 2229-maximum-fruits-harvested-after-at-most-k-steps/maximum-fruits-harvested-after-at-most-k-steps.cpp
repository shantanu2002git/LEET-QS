#define ll long long
class Solution {
public:
    int max_size = 2e5 + 10;
    int maxTotalFruits(vector<vector<int>>& nums, int start, int k) {

        vector<int> psum(max_size, 0);

        for (int i = 0; i < nums.size(); i++) {
            psum[nums[i][0]] = nums[i][1];
        }

        for (int i = 1; i < max_size - 2; i++) {
            psum[i] += psum[i - 1];
        }

        int l, r, ans = 0;

        for (r = start; r <= start + k && r < max_size - 2; r++) {
            l = min(start, start - k + (2 * (r - start)));

            if (l < 0) {
                l = 0;
                // if l is not in the range of  (start-k) , if it gives neg no.

                // then l=1
            }
            if (l != 0)
                ans = max(ans, (int)psum[r] - psum[l - 1]);
            else
                ans = max(ans, (int)psum[r]);
        }

        for (l = start; l >= start - k && l >= 0; l--) {
            r = max(start, start + k - 2 * (start - l));

            if (r >= max_size - 10) {
                r = max_size - 10;
            }

            if (l != 0)
                ans = max(ans, (int)psum[r] - psum[l - 1]);
            else {
                ans = max(ans, psum[r]);
            }
        }

        return ans;
    }
};