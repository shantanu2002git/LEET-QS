class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                          vector<int>& r) {
        vector<bool> res;
        int n = nums.size();
        int m = l.size();
        for (int i = 0; i < m; i++) {
            int lx = l[i], rx = r[i];
            vector<int> sub(nums.begin() + lx, nums.begin() + rx + 1);
            sort(sub.begin(), sub.end());
            int dif = sub[1] - sub[0];
            bool resA = true;
            for (int j = 2; j < sub.size(); j++) {
                if (sub[j] - sub[j - 1] != dif) {
                    resA = false;
                    break;
                }
            }
            res.push_back(resA);
        }
        return res;
    }
};
