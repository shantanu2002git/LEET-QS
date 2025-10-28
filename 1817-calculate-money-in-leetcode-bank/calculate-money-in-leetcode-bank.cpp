class Solution {
public:
    int totalMoney(int n) {
        int res = 0, pre = 0;
        while (n > 0) {
            for (int st = 1; st <= min(7, n); st++) {
                res += st + pre;
            }

            n -= 7;
            pre++;
        }
        return res;
    }
};