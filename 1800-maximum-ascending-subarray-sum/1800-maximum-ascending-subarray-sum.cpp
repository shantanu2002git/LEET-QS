class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), res = 0, li = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                li = li + nums[i];
                cout<<nums[i]<<" ";
                res = max(res, li);

            } else {
                cout<<endl;
                 res = max(res, li);
              li = nums[i];
            }
        }
         res = max(res, li);
        return res;
    }
};