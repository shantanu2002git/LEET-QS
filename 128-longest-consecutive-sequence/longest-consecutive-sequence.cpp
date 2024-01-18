#include <vector>
#include <algorithm> // for std::sort
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int cn = 1, mx = 1, n = nums.size();

        if (n == 0) return 0;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] != nums[i]) {
                if (nums[i] == nums[i - 1] + 1) {
                    cn++;
                } else {
                    mx = max(mx, cn);
                    cn = 1;
                }
            }
        }

        return max(mx, cn);
    }
};
