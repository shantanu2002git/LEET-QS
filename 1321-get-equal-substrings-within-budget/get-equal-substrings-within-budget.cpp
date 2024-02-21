class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int lf = 0, ri = 0;
        int cost = 0, mx = 0;
        while (ri < n) {
            cost += abs(s[ri] - t[ri]); // Corrected here, removed the redundant declaration of 'int' for 'cost'
            while (lf <= ri && cost > maxCost) {
                cost -= abs(s[lf] - t[lf]); // Corrected here, it should be subtraction
                lf++;
            }
            mx = max(mx, (ri - lf + 1));
            ri++;
        }
        return mx;
    }
};