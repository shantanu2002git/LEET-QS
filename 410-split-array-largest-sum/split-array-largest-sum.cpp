class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        int left = *max_element(nums.begin(), nums.end());
        int right = prefix[n-1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 1;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] > mid) {
                    count++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }
            if (count > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};