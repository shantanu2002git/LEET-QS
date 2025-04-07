class Solution {
public:
    int call(int idx, int n, vector<int>& nums, int xori) {
        if (idx >= n) {
            return xori;
        }
        int tt = 0, nn = 0;
        tt = call(idx + 1, n, nums, xori ^ nums[idx]);
        nn = call(idx + 1, n, nums,xori);

        return (tt + nn);
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), xori=0;
        return call(0, n, nums, xori);
    }
};