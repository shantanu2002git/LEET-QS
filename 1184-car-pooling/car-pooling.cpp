class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sort(trips.begin(), trips.end(),
        //      [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        vector<int> vis(1001, 0);
        for (auto it : trips) {
            vis[it[1]] += it[0];
            vis[it[2]] -= it[0];
        }
        int ps = 0;
        for (auto l : vis) {
            ps += l;
            if (ps > capacity) {
                return 0;
            }
        }
        return 1;
    }
};