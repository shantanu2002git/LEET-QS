class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size(), ls = 0;
        vector<int> res(n, 0);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i] * 2;
                nums[i + 1] = -1;
            } else if (nums[i] == 0) {
                nums[i] = -1;
            }
        }
        int i = 0;
        for (auto it : nums) {
            if (it == -1) {
                continue;
            }
            res[i++] = it;
        }
        return res;
    }
};