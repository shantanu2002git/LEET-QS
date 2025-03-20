class Solution {
public:
    void flipbit(vector<int>& nums, int i) {
        nums[i] = nums[i] ^ 1;
        nums[i + 1] = nums[i + 1] ^ 1;
        nums[i + 2] = nums[i + 2] ^ 1;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] == 1) {
                continue;
            } else {
                flipbit(nums, i);
                res++;
            }
        }
        if (nums[n - 2] == 0 || nums[n - 1] == 0) {
            return -1;
        }
        return res;
    }
};