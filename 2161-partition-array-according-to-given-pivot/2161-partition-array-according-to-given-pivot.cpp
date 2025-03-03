class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int piv) {
        vector<int> res;
        int pivele = 0;
        for (auto it : nums) {
            if (it < piv) {
                res.push_back(it);
            } else if (piv == it) {
                pivele++;
            }
        }
        while (pivele--) {
            res.push_back(piv);
        }

        for (auto it : nums) {
            if (it > piv) {
                res.push_back(it);
            }
        }
        return res;
    }
};