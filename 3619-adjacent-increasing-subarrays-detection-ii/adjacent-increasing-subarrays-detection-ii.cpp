class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int prevLen = 0;  // length of previous increasing subarray
        int curLen = 1;   // current increasing streak length
        int res = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                curLen++;
            } else {
                // when sequence breaks, compare with previous streak
                if (prevLen > 0) {
                    res = max(res, max(max(prevLen, curLen) / 2, min(prevLen, curLen)));
                }
                prevLen = curLen;
                curLen = 1; // reset
            }
        }

        // handle last streak
        if (prevLen > 0) {
            res = max(res, max(max(prevLen, curLen) / 2, min(prevLen, curLen)));
        }

        // special case: only one increasing sequence (no break)
        if (prevLen == 0) return curLen / 2;

        return res;
    }
};
