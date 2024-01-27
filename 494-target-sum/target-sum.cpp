class Solution {
public:
    int call(int idx, int res, int target, vector<int>& nums) {
        if (idx == -1) {
            return (res==target);//(res+nums[idx] == target || res-nums[idx]==target);
        } else if (idx < 0) {
            return 0;
        }
        int pos = call(idx - 1, res + nums[idx], target, nums);
        int neg = call(idx - 1, res - nums[idx], target, nums);

        return (pos + neg);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), res = 0;
        return call(n - 1, res, target, nums);
    }
};