class Solution {
public:
    vector<vector<int>> res;
    
    void call(vector<int>& can, int idx, int s, vector<int>& in) {
        if (s == 0) { 
            res.push_back(in);
            return;
        }

        for (int i = idx; i >= 0; i--) {
           
            if (i < idx && can[i] == can[i + 1])
                continue;

            if (can[i] <= s) {  
                in.push_back(can[i]);
                call(can, i - 1, s - can[i], in);
                in.pop_back();  // Backtrack
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> in;
        sort(candidates.begin(), candidates.end());  
        call(candidates, candidates.size() - 1, target, in);
        return res;
    }
};
