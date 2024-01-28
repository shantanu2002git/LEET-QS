#include <vector>

using namespace std;

class Solution {
public:
    bool call_dfs(int x, int y, int n, int m, vector<vector<int>>& grid) {
        if (x == n - 1 && y == m - 1) {
            return true;
        } else if (x >= n || y >= m || grid[x][y] == 0) {
            return false;
        }

        grid[x][y] = 0;
        return (call_dfs(x + 1, y, n, m, grid) || call_dfs(x, y + 1, n, m, grid));
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
       if(grid[0][0]==0 || grid[n-1][m-1]==0){
           return true;
       }
        // Call the DFS function once
        bool path1 = call_dfs(0, 0, n, m, grid);
        grid[0][0]=1;
        bool path2 = call_dfs(0, 0, n, m, grid);

        return  path2==false;
    }
};
