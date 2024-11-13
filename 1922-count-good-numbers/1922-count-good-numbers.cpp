class Solution {
public:
    const int md = 1e9 + 7;

    long long pow(long long x, long long r) {
        if (r == 0) {
            return 1;
        }

        return (r % 2 == 0) ?  pow(x * x % md, r / 2) % md : (x % md *  pow(x * x % md, r / 2) % md) % md;
    }

    int countGoodNumbers(long long n) {
        long long ev = (n / 2 + n % 2);  
        long long pr = (n / 2);         
        
        // Calculate (5^ev % md) * (4^pr % md) % md
        long long ans = (pow(5, ev) * pow(4, pr)) % md;

        return (int)ans;
    }
};
