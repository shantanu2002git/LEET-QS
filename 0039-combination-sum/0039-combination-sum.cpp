class Solution {
public:
    vector<vector<int>> res;
    void call(vector<int>& can, int idx, vector<int>& in, int s) {
        if (idx == -1) {
            if (s == 0) {
                res.push_back(in);
            }
            return;
        }

        if (can[idx] <= s) {
            in.push_back(can[idx]);
            call(can, idx , in, s - can[idx]);
            in.pop_back();
        }

        call(can, idx - 1, in, s);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> in;
        call(candidates, n - 1, in, target);
        return res;
    }
};