class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target = 0;
        vector<vector<int>> res;
        set<vector<int>>sit;
        for (int i = 0; i < n; i++) {
           
            int j = i+1, k = n - 1;
            while (j < k) {
                int intc = nums[i] + nums[j] + nums[k];
                if (intc > target) {
                    k--;
                } else if (intc < target) {
                    j++;
                } else {
                    sit.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }

        for(auto it : sit){
            res.push_back(it);
        }
        return res;
    }
};