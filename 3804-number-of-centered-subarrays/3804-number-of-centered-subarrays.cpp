class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            long long s = 0;
            for (int j = i; j < n; j++) {
                s = s + nums[j];
                for (int k = i; k <= j; k++) {
                    if (nums[k] == s) {
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};