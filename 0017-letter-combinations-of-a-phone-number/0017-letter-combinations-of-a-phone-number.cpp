class Solution {
public:
    vector<string> res;
    void backtrack(string digits, int idx, string curr, vector<string>& letters) {
        if (idx == digits.size()) {
            res.push_back(curr);
            return;
        }
        for (auto c : letters[digits[idx] - '0']) {
            curr.push_back(c);
            backtrack(digits, idx + 1, curr, letters);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, 0, "", letters);
        return res;
    }
};
