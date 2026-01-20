class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxLen = min(n, m);

        // Try larger squares first
        for (int k = maxLen; k >= 2; k--) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= m; j++) {

                    int target = 0;
                    for (int c = 0; c < k; c++)
                        target += grid[i][j + c];

                    bool ok = true;

                    // Check rows
                    for (int r = 0; r < k && ok; r++) {
                        int sum = 0;
                        for (int c = 0; c < k; c++)
                            sum += grid[i + r][j + c];
                        if (sum != target) ok = false;
                    }

                    // Check columns
                    for (int c = 0; c < k && ok; c++) {
                        int sum = 0;
                        for (int r = 0; r < k; r++)
                            sum += grid[i + r][j + c];
                        if (sum != target) ok = false;
                    }

                    // Check diagonals
                    int d1 = 0, d2 = 0;
                    for (int d = 0; d < k; d++) {
                        d1 += grid[i + d][j + d];
                        d2 += grid[i + d][j + k - 1 - d];
                    }

                    if (d1 != target || d2 != target)
                        ok = false;

                    if (ok) return k;
                }
            }
        }
        return 1;
    }
};
