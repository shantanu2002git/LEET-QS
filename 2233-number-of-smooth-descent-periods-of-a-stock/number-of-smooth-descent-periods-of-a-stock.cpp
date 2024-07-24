class Solution {
public:
    long long getDescentPeriods(vector<int>& prc) {
        long long res = 1, n = prc.size(), fl = 0;
        for (int i = 1; i < n; i++) {
            if (prc[i - 1] - prc[i] == 1) {
                res++;
            } else {
                res = 1;
            }
            fl = fl + res;
        }
        return fl+1;
    }
};