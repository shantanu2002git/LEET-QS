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
                /*when ele is work : 
               1. when pow is very less than tokens[0] then we can not do anything also sc=0 so we can not enter the ele if() condition
                so you can break there;

                2. now think sc>=1 but pow 5 and remaining tok[0]=4..tok1[3,2,1] on this time also we can not do any hting pow> tok{}

                3. 
                */
                break;
            }
        }
        return mx;
    }
};