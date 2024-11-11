class Solution {
public:
    long long minEnd(int n, int x) {
        long long res=x;
        while(--n){
            res=(res+1) | x;
        }
        return res;
    }
};
/*
 we take the current number and increment it. But after incrementing, 
 we force the new number to keep the bit pattern of x by applying a bitwise OR with x. 
 This ensures that no bits from x are lost in the process,
and we continue this until the last element is constructed.
The result is the smallest last element that satisfies both 
conditions: strictly increasing order and preserving the AND operation result as x.
--------------------------------------------------------------
Input: n = 2, x = 7
Output: 15
nums can be [7,15] and its last element is 15.
*/