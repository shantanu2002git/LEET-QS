class Solution {
public:
    vector<vector<int>> res;
    void call(vector<int> nums, int idx, vector<int>& in) {
        if (idx == -1) {
            res.push_back(in);
            return;
        }
        
        in.push_back(nums[idx]);
        call(nums, idx - 1, in);
        in.pop_back();

        int prv = idx - 1;
        while (prv > 0 && nums[idx] == nums[prv]) {
            prv--;
        }

        call(nums, prv, in);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> in;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        call(nums, n - 1, in);
        return res;
    }
};