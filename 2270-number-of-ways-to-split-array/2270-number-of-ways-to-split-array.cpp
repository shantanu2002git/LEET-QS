class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pref(n, 0);
     
        long long sum = accumulate(nums.begin(), nums.end(), 0LL); // Use 0LL to ensure the sum is long long
        pref[0] = nums[0];
        long long res = 0;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
            if (pref[i - 1] >= (sum - pref[i - 1])) {
                res++;
            }
        }

        return res;
    }
};
