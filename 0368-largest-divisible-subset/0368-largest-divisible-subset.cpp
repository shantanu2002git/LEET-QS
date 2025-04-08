class Solution {
public:
    vector<int> largeres;
    void call(int idx, int n, int prev, vector<int>& nums, vector<int>& res) {
        if (idx >= n) {
            if (largeres.size() < res.size()) {
                largeres = res;
            }
            return;
        }
        if (prev == -1 || nums[idx] % prev == 0) {
            res.push_back(nums[idx]);
            cout << nums[idx] << " ";
            call(idx + 1, n, nums[idx], nums, res);
            res.pop_back();
        }
        call(idx + 1, n, prev, nums, res);
    }
    vector<int> largestDivisibleSubset_call(vector<int>& nums) {
        vector<int> res;
        int n = nums.size(), prev = -1;

        sort(nums.begin(), nums.end());
        call(0, n, prev, nums, res);
        return largeres;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Step 1: Sort the input array to ensure divisibility conditions are
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Step 2: Initialize DP and parent arrays
        vector<int> dp(n, 1);
        // dp[i] stores the size of the largest subset ending at i
        vector<int> parent(n, -1); // parent[i] helps reconstruct the subset
        int maxSize = 0;           // To track the size of the largest subset
        int maxIndex = -1; // To track the ending index of the largest subset

        // Step 3: Fill the DP and parent arrays
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Check if nums[i] is divisible by nums[j]
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1; // Update the size of the subset
                    parent[i] = j;
                    // Update the parent to reconstruct the subset
                }
            }

            // Update the largest subset size and its ending index
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }

        // Step 4: Reconstruct the largest subset
        vector<int> result;
        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            // Add the current element to the result
            maxIndex = parent[maxIndex]; // Move to the parent
        }

        reverse(result.begin(), result.end());
        // Reverse to get the correct order
        return result;
    }
};