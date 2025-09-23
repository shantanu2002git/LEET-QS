class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inv) {

        vector<vector<int>> res;
        sort(inv.begin(), inv.end());
        for (auto it : inv) {
            if (res.empty()) {
                res.push_back(it);
            } else {
                if (res.back()[1] >= it[0]) {
                    res.back()[1] = max(res.back()[1], it[1]);

                } else {
                    res.push_back(it);
                }
            }
        }
        return res;
    }
};