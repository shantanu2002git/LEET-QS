class Solution {
public:
    int minimumRecolors(string s, int k) {
        int res = 1e9;
        int n = s.size(), wt = 0, i = 0, bl = 0, j = 0;
        while (i < n) {
            if (s[i] == 'W') {
                wt++;
            } else {
                bl++;
            }
            while (
                (i - j + 1) > k) {
                wt = wt - (s[j] == 'W');
                bl = bl - (s[j] == 'B');
                res = min(wt, res);
                j++;
            }
            if((i-j+1)==k){

            
             res=min(wt,res);
            }
            i++;
        }
        res = min(wt, res);
        return res;
    }
};