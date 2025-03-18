class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ls = strs[strs.size() - 1];
        string fs = strs[0], res = "";
        int i;
        for (i = 0; i < min(fs.size(), ls.size()); i++) {
            if (ls[i] != fs[i]) {
                break;
            }
        }
        return fs.substr(0, i );
    }
};