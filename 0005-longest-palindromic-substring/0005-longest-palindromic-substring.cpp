class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int lenmx = 0, st = 0;

        for (int l = 0; l < n; l++) {
            // Odd-length palindrome (centered at s[l])
            int i = l, j = l;
            while (i >= 0 && j < n && s[i] == s[j]) {
                if (j - i + 1 > lenmx) {
                    lenmx = j - i + 1;
                    st = i;
                }
                i--; j++;
            }

            // Even-length palindrome (centered at s[l] and s[l+1])
            i = l, j = l + 1;
            while (i >= 0 && j < n && s[i] == s[j]) {
                if (j - i + 1 > lenmx) {
                    lenmx = j - i + 1;
                    st = i;
                }
                i--; j++;
            }
        }

        return s.substr(st, lenmx);
    }
};
