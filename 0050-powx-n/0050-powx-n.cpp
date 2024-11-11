class Solution {
public:
    double call(double x, int n) {
        if (n == 0) {
            return 1;
        }
       // return x * call(x, n - 1);
       return (n%2==0 )  ? call(x*x, n/2) : x*call(x*x,n/2);
    }
    double myPow(double x, int n) {
        if (n < 0) {
            return 1 / call(x, abs(n));
        }
        return call(x, n);
    }
};