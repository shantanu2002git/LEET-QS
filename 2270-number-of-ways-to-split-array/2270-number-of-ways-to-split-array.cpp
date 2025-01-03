class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0);
        vector<int> suf(n, 0);
        int sum = reduce(nums.begin(), nums.end(), 0);
        pref[0] = nums[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (pref[i - 1] >= (sum - pref[i - 1])) {
                res++;
            }
            pref[i] = pref[i - 1] + nums[i];
        }

        return res;
    }
};