class Solution {
public:
    int hammingDistance(int n, int m) {
       int bit = n ^ m;
    int res = 0;
    while (bit)
    {
        res += bit & 1;
        bit >>= 1;
    }
    return res;
    }
};