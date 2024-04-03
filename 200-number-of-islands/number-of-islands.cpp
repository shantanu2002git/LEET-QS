class Solution {
public:
    int n, m;
    bool is_in(int x, int y) { return (x < n && x >= 0 && y < m && y >= 0); }
    void call(int x, int y, vector<vector<char>>& grid) {
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        queue<pair<int, int>> q;

        q.push({x, y});
        grid[x][y] = '0';
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto it = q.front();
                q.pop();
                int nx = it.first, ny = it.second;
                for (int i = 0; i < 4; i++) {
                    int dnx = nx + dx[i], dny = ny + dy[i];
                    if (is_in(dnx, dny) && grid[dnx][dny] == '1') {
                        q.push({dnx, dny});
                        grid[dnx][dny] = '0';
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    call(i, j, grid);
                    c++;
                }
            }
        }
        return c;
    }
};