class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort the array to check neighbors
        vector<int> res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Check if the current number is lonely
            bool isLonely =
                (i == 0 ||
                 nums[i] !=
                     nums[i - 1] +
                         1) && // Not consecutive with the previous number
                (i == n - 1 ||
                 nums[i] !=
                     nums[i + 1] - 1) && // Not consecutive with the next number
                (i == 0 ||
                 nums[i] !=
                     nums[i - 1]) && // Not a duplicate of the previous number
                (i == n - 1 ||
                 nums[i] != nums[i + 1]); // Not a duplicate of the next number

            if (isLonely) {
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};
