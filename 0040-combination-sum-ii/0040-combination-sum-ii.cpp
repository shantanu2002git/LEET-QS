class Solution {
public:
    vector<vector<int>> res;

    void call(vector<int>& can, vector<int>& in, int idx, int s) {
        if (s == 0) {
            res.push_back(in);
            return;
        }
        if (idx < 0 || s < 0) {
            return;
        }
        in.push_back(can[idx]);
        call(can, in, idx - 1, s - can[idx]);
        in.pop_back(); // Backtrack
        int prevIdx = idx - 1;
        while (prevIdx >= 0 && can[prevIdx] == can[idx]) {
            prevIdx--;
        }

        // Recurse without including the current element, starting from previous
        // unique element
        call(can, in, prevIdx, s);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to manage duplicates
        vector<int> in;
        call(candidates, in, candidates.size() - 1, target);
        return res;
    }
};
