class Solution {
public:
    int path(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (col < 0 || col >= grid.size()) return 1e8;
        if (row == 0) return grid[row][col];


        if (dp[row][col] != -1) return dp[row][col];
        int ans = INT_MAX;
        
        for (int cl = 0; cl < grid.size(); cl++) {
            if(cl!=col){
            ans = min(ans, grid[row][col] + path(row - 1, cl, grid, dp));
            }
        }
        return dp[row][col] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int minimum = INT_MAX;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

        for (int i = 0; i < grid.size(); i++) {
            minimum = min(minimum, path(grid.size() - 1, i, grid, dp));
        }

        return minimum;
    }
};
