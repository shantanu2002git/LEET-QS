class Solution {
public:
    pair<int, int> call_maxKadane(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, maxSum = INT_MIN;
        int start = 0, maxStart = 0, maxEnd = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum > maxSum) {
                maxSum = sum;
                maxStart = start;
                maxEnd = i;
            }

            if (sum < 0) {
                sum = 0;
                start = i + 1; // Reset start index
            }
        }
        return {maxSum, maxEnd - maxStart + 1}; // Return max sum and its length
    }

    pair<int, int> call_minKadane(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, minSum = INT_MAX;
        int start = 0, minStart = 0, minEnd = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum < minSum) {
                minSum = sum;
                minStart = start;
                minEnd = i;
            }

            if (sum > 0) {
                sum = 0;
                start = i + 1; // Reset start index
            }
        }
        return {minSum, minEnd - minStart + 1}; // Return min sum and its length
    }

    pair<int, int> maxAbsoluteSum_len(vector<int>& nums) {
        auto [maxSum, maxLen] = call_maxKadane(nums);
        auto [minSum, minLen] = call_minKadane(nums);

        if (abs(minSum) > maxSum) {
            return {abs(minSum),
                    minLen}; // Take minKadane if its absolute sum is larger
        } else {
            return {maxSum, maxLen}; // Take maxKadane otherwise
        }
    }
    int maxAbsoluteSum(vector<int>& nums) {
        auto [sum, len] = maxAbsoluteSum_len(nums);
        return sum;
    }
};