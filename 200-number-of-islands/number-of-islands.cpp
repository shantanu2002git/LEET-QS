class Solution {
public:
    void call(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i >= n || j >= m || i < 0 || j < 0) {
            return;
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1') {
               // grid[nx][ny] = '0';
                call(grid, nx, ny, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    call(grid, i, j, n, m);
                    res++;
                }
            }
        }
        return res;
    }
};