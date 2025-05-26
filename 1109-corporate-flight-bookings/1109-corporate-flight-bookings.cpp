class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& book, int n) {
        vector<int> pref(n + 1, 0);
        for (auto it : book) {

            pref[it[0]] = pref[it[0]] + it[2];
            if (it[1] + 1 <= n) {
                pref[it[1] + 1] = -it[2] + pref[it[1] + 1];
            }
        }
        vector<int> res(n + 1, 0);
        res[1] = pref[1];
        for (int i = 2; i <= n; i++) {
            res[i] = res[i - 1] + pref[i];
        }
        reverse(res.begin(), res.end());
        res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};