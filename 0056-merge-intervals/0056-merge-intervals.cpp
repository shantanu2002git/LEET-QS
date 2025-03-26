class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        sort(intv.begin(), intv.end());
        vector<vector<int>> res;
        int prvls = 0;
        for (int i = 0; i < intv.size(); i++) {
            if (res.empty()) {
                res.push_back(intv[i]);
            } else {
                if (intv[i][0] <= res.back()[1]) {
                    res.back()[1] = max(res.back()[1], intv[i][1]);
                } else {
                    res.push_back(intv[i]);
                }
            }
        }
        return res;
    }
};
