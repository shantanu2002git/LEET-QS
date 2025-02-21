class Solution {
public:
    int res = 0;
    void call(int idx, string txt) {
        int n = txt.size();
        if (idx >= n)
            return;
        for (int i = 1; i < n - idx; i++) {
            string si = txt.substr(idx, i);
            string ls = txt.substr(n - idx - 1, i);

            if (si == ls) {
                res++;
            }

            call(idx + 1, txt);
        }
    }
    int longestDecomposition(string text) { call(0, text);
    return res; }
};