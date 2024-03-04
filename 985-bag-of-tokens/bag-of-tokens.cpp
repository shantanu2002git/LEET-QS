class Solution {
public:
    int bagOfTokensScore(vector<int>& tok, int pow) {
        sort(tok.begin(), tok.end());
        int n = tok.size(), i = 0, j = n - 1;
        int sc = 0, mx = 0;
        while (i <= j) {
            if (tok[i] <= pow) {
                pow = pow - tok[i++];
                sc++;
                mx = max(mx, sc);
            } else if (sc >= 1 && tok[i] > pow) {
                pow = pow + tok[j--];
                sc--;
            } else {
                break;
            }
        }
        return mx;
    }
};