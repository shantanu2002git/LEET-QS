class Solution {
public:
    void call(int i, int j, int s, int &mxi, vector<vector<int>>& grid,
              vector<vector<int>>& vis, int n, int m) {
        if (i >= n || j >= m || i < 0 || j < 0 || vis[i][j]==1 || grid[i][j]==0) {
            mxi=max(mxi,s);
            return;
        }
        vis[i][j] = 1;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        s = s + grid[i][j];
        int nwx, nwy;
        for (int l = 0; l < 4; l++) {
            nwx = dx[l] + i, nwy = dy[l] + j;
            // if (vis[nwx][nwy] == 0 && grid[nwx][nwy] != 0) {
                call(nwx, nwy, s, mxi,grid, vis, n, m);
            // }
        }
        // s = s - grid[i][j];
        vis[i][j] = 0;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<int>> vis(n, vector<int>(m, 0));
                int s = 0,mxi=-1;
                call(i, j, s,mxi, grid, vis, n, m);
                mx = max(mx, mxi);
            }
        }
        return mx;
    }
};