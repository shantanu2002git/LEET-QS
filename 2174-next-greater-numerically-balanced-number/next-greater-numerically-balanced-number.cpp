class Solution {
public:
    bool isVaild(int v) {
        vector<int>dig(10);
        while (v > 0) {
            dig[v % 10]++;
            v = v / 10;
        }
        for (int d = 0; d <= 9; d++) {
            if (dig[d] > 0 && dig[d] != d) {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        /*
        Limit n=1e6 : 1 000 000
                      1 224 444
        */
        for (int i = n + 1; i <=1224444 ; i++) {
            if (isVaild(i)) {
                return i;
            }
        }
        return -1;
    }
};