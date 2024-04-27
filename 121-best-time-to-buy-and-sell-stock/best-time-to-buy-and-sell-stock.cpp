class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        int  mi = 1e9, res = -0;
        for (int i = 0; i < n; i++) {
           
            mi = min(mi, p[i]);
            res = max(res,  p[i]-mi);
        }
        return res;
    }
};