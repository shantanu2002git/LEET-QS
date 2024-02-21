class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), cost = 0, lf = 0, ri = 0, res = 0, mx = 0;
        while (lf < n) {
            cost = cost + abs(s[lf] - t[lf]);
           
                while (cost > maxCost) {
                    cost = cost - abs(s[ri] - t[ri]);
                    ri++;
                }
         
            mx = max(mx, lf - ri + 1);
            lf++;
        }
        return mx;
    }
};