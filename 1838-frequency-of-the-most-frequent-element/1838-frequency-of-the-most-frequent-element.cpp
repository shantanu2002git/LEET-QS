class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
         long long n = nums.size();
         long long i = 0, j = 0, mx = -1;
        long long sum = 0;
        while (i < n) {
            sum = sum + nums[i];
            while (nums[i] * (i - j + 1) > sum + k) {
                sum = sum - nums[j];
                j++;
            }
            mx = max(mx, i - j + 1);
            i++;
        }
        return mx;
    }
};