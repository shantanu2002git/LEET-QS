class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inv) {
        sort(inv.begin(), inv.end(), [&](vector<int>& a, vector<int>& b) {
            return (a[1] < b[1]);
        }); int resmove = 0;
        int mx = inv[0][1];
        for (int i = 1; i < inv.size(); i++) {
            if (mx > inv[i][0]) {
                resmove++;

            } else {
                mx = max(mx, inv[i][1]);
            }
        }

        return resmove;
    }
};