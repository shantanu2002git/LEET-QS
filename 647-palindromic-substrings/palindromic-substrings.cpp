class Solution {
public:
    bool validp(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size(), c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string sub = s.substr(i, j - i + 1); // Adjusting substring generation
                if (validp(sub)) {
                    c++;
                }
            }
        }
        return c;
    }
};