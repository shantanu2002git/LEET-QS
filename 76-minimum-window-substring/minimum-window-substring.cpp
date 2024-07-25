class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        map<char, int> mp1, mp2;
        for (char c : t) {
            mp1[c]++;
        }
        int n = s.size(), m = t.size();
        int i = 0, j = 0, c = 0; 
        int min_len = INT_MAX;
        int start = 0;

        while (i < n) {
            mp2[s[i]]++;
          if (mp2[s[i]] <= mp1[s[i]]) {
                c++;
            }
           while (c >= m) {
              if (i - j + 1 < min_len) {
                    min_len = i - j + 1;
                    start = j;
                }
                mp2[s[j]]--;
                if (mp2[s[j]] < mp1[s[j]]) {
                    c--;
                }
                j++;
            }
            
            i++;
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
