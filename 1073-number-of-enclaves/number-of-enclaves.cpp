class Solution {
public:
    int n, m;
    void DFS(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1){
            return;
        }
        grid[x][y] = 0;
        DFS(grid, x - 1, y);
        DFS(grid, x, y - 1);
        DFS(grid, x + 1, y);
        DFS(grid, x, y + 1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
         if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1){
                    DFS(grid, i, j);
                }
            }
        } 
        int c = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    c++;
                }
            }
        } 
        return c;
    }
};
