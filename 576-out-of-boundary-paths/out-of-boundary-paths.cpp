class Solution {
public:
    const int MOD = 1000000007;

    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
         vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(m+1,vector<int>(maxMove+1,-1)));
        return call(n, m, maxMove, startRow, startColumn, dp);
    }

    int call(int n, int m, int maxMove, int x, int y, vector<vector<vector<int>>>& dp) {
        if (x < 0 || y < 0 || x >= n || y >= m) {
            return 1;
        }

        if (maxMove == 0) {
            return 0;
        }

        if (dp[x][y][maxMove] != -1) {
            return dp[x][y][maxMove] ;
        }

        long tp = call(n, m, maxMove - 1, x + 1, y, dp);
        long dw = call(n, m, maxMove - 1, x - 1, y, dp);
        long rw = call(n, m, maxMove - 1, x, y + 1, dp);
        long lf = call(n, m, maxMove - 1, x, y - 1, dp);

        return  dp[x][y][maxMove] = (tp% MOD + dw% MOD + rw% MOD + lf% MOD) % MOD;
    }
};
