class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
      //  vector<vector<long long>> count(n, vector<long long>(m, 0));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dis[0][0] = 0;
       // count[0][0] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;

            for (int i = 0; i < 4; i++)
            {
                int nwx = x + dx[i], nwy = y + dy[i];
                if (nwx >= 0 && nwx < n && nwy >= 0 && nwy < m)
                {
                    int newCost = grid[nwx][nwy] + dis[x][y];
                    if (newCost < dis[nwx][nwy])
                    {
                        dis[nwx][nwy] = newCost;
                     //   count[nwx][nwy] = count[x][y]; // Reset count for new minimum cost
                        q.push({nwx, nwy});
                    }
                    else if (newCost == dis[nwx][nwy])
                    {
                      //  count[nwx][nwy] += count[x][y]; // Add paths for equal cost
                    }
                }
            }
        }

      //  cout << count[n - 1][m - 1] << endl; // Number of paths with minimum cost
        return dis[n - 1][m - 1];            // Minimum cost to reach the endpoint
    }
};