class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        int fs = 1, ls = x;
        while (fs <= ls) {
            long long mid = fs + (ls - fs) / 2;  // avoid fs+ls overflow
            long long sq = mid * mid;            // force 64-bit multiplication

            if (sq == x) {
                return (int)mid;
            }
            if (sq > x) {
                ls = mid - 1;
            } else {
                fs = mid + 1;
            }
        }
        return ls; 
    }
};
