class Solution {
public:
    double call(double e, int p) {
        if (p == 0) {
            return 1;
        }
        return p % 2 == 0 ? myPow(e * e, p / 2) : e * myPow(e * e, p / 2);
    }
    double myPow(double x, int n) {
        if (n < 0) {
            n = abs(n);
            x = 1 / x;
        }
        return call(x, n);
    }
};

/*
     Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/