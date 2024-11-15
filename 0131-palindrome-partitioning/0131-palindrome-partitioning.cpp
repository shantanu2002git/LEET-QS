class Solution {
public:
    vector<vector<string>> res;
    bool isPalidrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void call(int idx, string s, vector<string>& in) {
        if (idx >= s.size()) {
            res.push_back(in);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (isPalidrome(s, idx, i)) {
                in.push_back(s.substr(idx, i - idx + 1));
                call(i + 1, s, in);
                in.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> in;
        call(0, s, in);
        return res;
    }
};