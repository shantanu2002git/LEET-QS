class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), s = 0, mx = -1e9;
int elemx=-1e9;
        for (int i = 0; i < n; i++) {
            s = s + nums[i];
            if (s < 0) {
                s = 0;
            }
            mx = max(s, mx);
            elemx=max(elemx,nums[i]);
        }
        return mx==0 ? elemx :max(mx,elemx);
    }
};