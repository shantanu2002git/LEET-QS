
class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        int mx = *max_element(nums.begin(), nums.end()) + k;
        vector<int> rnge(mx + 2, 0); // Use mx+2 to prevent overflow during increments

        // Mark ranges for each number
        for (auto it : nums)
        {
            int inc = it + k, dec = max(it - k, 0);
            rnge[dec] += 1;
            rnge[inc + 1] -= 1; // Increment past the range end
        }

        // Calculate prefix sums to determine the maximum overlapping range
        int maxBeauty = 0, current = 0;
        for (int i = 0; i <= mx; i++)
        {
            current += rnge[i];
            maxBeauty = max(maxBeauty, current);
        }

        return maxBeauty;
    }
};