class Solution {
public:
    void call(vector<vector<char>>& grid, int n, int m, int ix, int jy) {
        if (ix < 0 || jy < 0 || ix >= n || jy >= m) {
            return;
        }

        grid[ix][jy] = '0';
               int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        

        for (int i = 0; i < 4; i++) {
            int nwx = ix + dx[i], nwy = jy + dy[i];
            if (nwx >= 0 && nwx < n && nwy >= 0 &&
                nwy < m && grid[nwx][nwy] == '1' ) {
                call(grid, n, m, nwx, nwy);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    call(grid, n, m, i, j);
                    res++;
                }
            }
        }

        return res;
    }
};