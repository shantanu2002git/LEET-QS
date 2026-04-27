class Solution {
public:
    int n, m;
    unordered_map < int, vector<vector<int>>> dairection = {
                             {1, {{0, -1}, {0, 1}}},  {2, {{-1, 0}, {1, 0}}},
                             {3, {{0, -1}, {1, 0}}},  {4, {{0, 1}, {1, 0}}},
                             {5, {{-1, 0}, {0, -1}}}, {6, {{-1, 0}, {0, 1}}},
    };

    bool calldfs(vector<vector<int>>& grid, int x, int y,
                 vector<vector<bool>>& visit) {
                    if(x==n-1 && y==m-1) return true;
        visit[x][y] = true;
        for (auto& dir : dairection[grid[x][y]]) {
            int nwi = x + dir[0], nwj = y + dir[1];
            if (nwi < 0 || nwi >= n || nwj < 0 || nwj >= m || visit[nwi][nwj])
                continue;

            for (auto& backdir : dairection[grid[nwi][nwj]]) {
                if (nwi + backdir[0] == x && nwj + backdir[1] == y) {
                    if (calldfs(grid, nwi, nwj, visit)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visit(n+1, vector<bool>( m+1, false));
        return calldfs(grid, 0, 0, visit);
    }
};