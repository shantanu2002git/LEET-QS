class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        q.push({
            0,
            0,
        });
        dis[0][0] = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int pathd = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;
            //  q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nwx = x + dx[i], nwy = y + dy[i];
                if (nwx < n && nwx >= 0 && nwy < m && nwy >= 0)
                {
                    int newcost = grid[nwx][nwy] + dis[x][y];
                    if (dis[nwx][nwy] > newcost)
                    {
                        dis[nwx][nwy] = newcost;
                        q.push({nwx, nwy});
                    }
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};
