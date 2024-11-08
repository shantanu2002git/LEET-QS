class Solution {
public:
    bool check(vector<int>& nums, int i, int j) {
        // Create a temporary copy of the subarray [i, j] and sort it
        vector<int> temp(nums.begin() + i, nums.begin() + j + 1);
        sort(temp.begin(), temp.end());

        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        for (int k = i; k <= j; k++) {
            if (temp[k - i] !=
                sorted_nums[k]) { // Use k - i to index temp correctly
                return false;
            }
        }
        return true;
    }
    // https://youtu.be/vsGqN6YSXAg?si=S9AiEfUASpGO5z_u
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> bitc(n);
        for (int i = 0; i < n; i++) {
            bitc[i] = __builtin_popcount(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            int j = i;
            // Find the range [i, j] where all numbers have the same bit count
            while (j + 1 < n && bitc[j] == bitc[j + 1]) {
                j++;
            }

            // Check if the subarray [i, j] can be sorted independently
            if (!check(nums, i, j)) {
                return false;
            }

            // Move `i` to the end of the current segment
            i = j;
        }
        return true;
    }
};
