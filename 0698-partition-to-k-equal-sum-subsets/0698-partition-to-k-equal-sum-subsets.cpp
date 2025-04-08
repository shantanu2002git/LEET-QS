class Solution {
public:
    bool back(vector<int>& nums, vector<int>& visit, int tar, int currSum,
              int idx, int k) {
        int n = nums.size();
        if (k == 0) {
            return true;
        }

        if (currSum == tar) {
            return back(nums, visit, tar, 0, 0, k - 1);
        }
        for (int j = idx; j < n; j++) {
            if (visit[j] || currSum + nums[j] > tar)
                continue;

            visit[j] = true;
            if (back(nums, visit, tar, currSum + nums[j], j + 1, k))
                return true;
            visit[j] = false;
        }

        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        int n = nums.size();
        if (n < k || sum % k != 0)
            return false;

        vector<int> visit(n, 0);
        return back(nums, visit, sum / k, 0, 0, k);
    }
};