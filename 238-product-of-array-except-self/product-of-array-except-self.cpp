class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), start = 1, end = 1;
        vector<int> res(n, 1);
       
        int fromBegin = 1;
        int fromLast = 1;
      

        for (int i = 0; i < n; i++) {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n - 1 - i] *= fromLast;
            fromLast *= nums[n - 1 - i];
        }
        return res;
    }
};