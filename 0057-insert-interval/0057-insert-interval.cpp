class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& in) {
        vector<vector<int>> res;
        int n = inv.size(), i = 0;

        // Step 1: Add intervals that end before 'in' starts : left side 
        while (i < n && inv[i][1] < in[0]) {
            res.push_back(inv[i]);
            i++;
        }

        // Step 2: Merge overlapping intervals  : match condition middle side
        int mins = in[0], mxi = in[1];  
        while (i < n && inv[i][0] <= in[1]) {
            mins = min(mins, inv[i][0]);
            mxi = max(mxi, inv[i][1]);
            i++;
        }
        res.push_back({mins, mxi});

        // Step 3: Add remaining intervals after merging : ending is not overlap so insert it
        while (i < n) {
            res.push_back(inv[i]);
            i++;
        }

        return res;
    }
};
