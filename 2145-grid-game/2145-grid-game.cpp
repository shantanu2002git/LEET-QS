class Solution
{
public:
    vector<vector<long long>> calculateSuffixSum(vector<vector<int>> &grid)
    {
        int n = grid[0].size();
        vector<vector<long long>> suffix(2, vector<long long>(n, 0));

        suffix[0][n - 1] = grid[0][n - 1];
        suffix[1][n - 1] = grid[1][n - 1];

        for (int i = n - 2; i >= 0; --i)
        {
            suffix[0][i] = suffix[0][i + 1] + grid[0][i];
            suffix[1][i] = suffix[1][i + 1] + grid[1][i];
        }

        return suffix;
    }

    long long gridGame(vector<vector<int>> &grid)
    {
        int n = grid[0].size();
        vector<vector<long long>> suffixSum = calculateSuffixSum(grid);

        long long result = LLONG_MAX;

        long long prefixSumBottom = 0;

        for (int i = 0; i < n; ++i)
        {
            // Remaining top row sum after Robot 1 moves right from column i
            long long topRemaining = (i + 1 < n) ? suffixSum[0][i + 1] : 0;

            // Collected bottom row sum if Robot 1 moves down to bottom row at column i
            long long bottomCollected = prefixSumBottom;

            // Robot 2 will force Robot 1 to take the max of these two
            long long maxScore = max(topRemaining, bottomCollected);

            // Minimize Robot 1's maximum score
            result = min(result, maxScore);

            // Update prefix sum for bottom row as we move to the next column
            prefixSumBottom += grid[1][i];
        }

        return result;
    }
};
