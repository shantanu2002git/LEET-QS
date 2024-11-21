class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakidx = -1;

        // Find the first number that is smaller than the next one, starting from the end
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakidx = i;
                break;
            }
        }

        // If no such number exists, the array is in descending order, reverse it
        if (breakidx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the smallest number that is larger than nums[breakidx] from the end
        for (int i = n - 1; i > breakidx; i--) {
            if (nums[i] > nums[breakidx]) {
                swap(nums[i], nums[breakidx]);
                break;
            }
        }

        // Reverse the elements after breakidx to get the smallest next permutation
        sort(nums.begin() + breakidx + 1, nums.end());
    }
};
