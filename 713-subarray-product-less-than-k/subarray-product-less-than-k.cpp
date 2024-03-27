class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;

        int ans = 0;
        int prod = 1;

        while (j < n) {
            prod *= nums[j];
            j++;
            while (prod >= k && i < j) {
                prod /= nums[i];
                i++;
            }
            ans += (j - i);
        }
        return ans;
    }
};