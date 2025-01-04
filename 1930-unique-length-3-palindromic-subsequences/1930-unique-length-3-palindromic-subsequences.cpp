class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        unordered_set<string> unique_palindromes;

        // Record the first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        // Check for palindromic subsequences
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && last[i] != -1 && first[i] != last[i]) {
                unordered_set<char> middle_chars;
                for (int j = first[i] + 1; j < last[i]; j++) {
                    middle_chars.insert(s[j]);
                }
                for (char c : middle_chars) {
                    unique_palindromes.insert(string(1, 'a' + i) + c + string(1, 'a' + i));
                }
            }
        }

        return unique_palindromes.size();
    }
};
