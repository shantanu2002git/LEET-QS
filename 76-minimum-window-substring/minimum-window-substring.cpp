class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (m > n) {
            return "";
        }
        unordered_map<char, int> mp1, mp2;
        for (auto it : t) {
            mp1[it]++;
        }
        int cnt = 0, i = 0, j = 0, mi = INT_MAX, start = 0;
        while (i < n) {
            mp2[s[i]]++;
            if (mp1[s[i]] > 0 && mp2[s[i]] <= mp1[s[i]]) {
                cnt++;
            }
            if (cnt == m) {
                while (mp2[s[j]] > mp1[s[j]] || mp1[s[j]] == 0) {
                    mp2[s[j]]--;
                    j++;
                }
                if (mi > i - j + 1) {
                    mi = i - j + 1;
                    start = j;
                }
            }
            i++;
        }
        if (mi == INT_MAX) {
            return "";
        }
        return s.substr(start, mi);
    }
};