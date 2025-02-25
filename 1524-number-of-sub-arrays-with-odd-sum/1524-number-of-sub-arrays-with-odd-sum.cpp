#include <vector>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int prfx = 0, evn = 1, odd = 0, res = 0;
        const int md = 1e9 + 7;

        for (auto it : arr) {
            prfx = prfx + it; // Maintain cumulative sum
            
            if (prfx % 2 == 0) { // Even prefix sum
                res = (res + odd) % md;
                evn++; // Increment count of even prefix sums
            } else { // Odd prefix sum
                res = (res + evn) % md;
                odd++; // Increment count of odd prefix sums
            }
        }
        return res;
    }
};
