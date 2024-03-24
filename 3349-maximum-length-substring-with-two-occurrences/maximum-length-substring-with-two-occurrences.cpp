class Solution {
public:
    int maximumLengthSubstring(string s) {
        int mx = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> fq(26, 0);
            for (int j = i; j < n; j++) {
                if (++fq[s[j] - 'a'] > 2) {
                    break;
                }
                mx = max(mx, j - i + 1);
            }
        }
        return mx;
    }
};