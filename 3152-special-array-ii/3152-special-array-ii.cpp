#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> record(n, 0); // Prefix sum for counting odd numbers
        vector<bool> res;

        // Step 1: Build prefix sum of odd numbers
        record[0] = nums[0] % 2; // 1 if nums[0] is odd, 0 otherwise
        for (int i = 1; i < n; i++)
        {
            record[i] = record[i - 1] + (nums[i] % 2);
        }

        // Step 2: Process each query
        for (auto &query : queries)
        {
            int left = query[0], right = query[1];
            int oddCount;

            // Calculate odd numbers in subarray [left, right]
            if (left == 0)
            {
                oddCount = record[right];
            }
            else
            {
                oddCount = record[right] - record[left - 1];
            }

            // Step 3: Determine if subarray is "special"
            // For this example, let's consider "special" means having an even count of odd numbers
            bool isSpecial = (oddCount % 2 == 0); // Modify as needed based on the problem
            res.push_back(!isSpecial);
        }

        return res;
    }
};
