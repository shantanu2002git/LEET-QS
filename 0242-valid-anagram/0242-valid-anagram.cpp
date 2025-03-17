class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int n = s.size(), m = t.size();
        if (n != m) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                return 0;
            }
        }
        return 1;
    }
};