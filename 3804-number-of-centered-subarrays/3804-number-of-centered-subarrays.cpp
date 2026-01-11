class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
           map<long long, int>mps;
           long long s=0;
            for (int j = i; j < n; j++) {
                s = s + nums[j];
                mps[nums[j]]++;
                // for (int k = i; k <= j; k++) {
                    if (mps.count(s)) {
                        res++;
                        // break;
                    }
                // }
            }
        }
        return res;
    }
};