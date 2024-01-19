/*

    Time Complexity : O(N*M), where N is the number of rows and M is the number of columns of matrix(grid).
    Space Complexity : O(N*M), Visited matrix space.

    Solved Using Array + Matrix + DFS.

*/

class Solution {
private: 
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int row, int col, 
    vector<vector<int>>& visited, int dxdy[][4], bool& flag){
        int n = grid1.size();
        int m = grid1[0].size();

        if(grid1[row][col] == 0){
            flag = false;
        }
        
        visited[row][col] = 1;

        for(int i=0; i<4; i++){
            int newrow = row + dxdy[i][0];
            int newcol = col + dxdy[i][1];
            if(newrow>=0 && newcol>=0 && newrow<n && newcol<m && !visited[newrow][newcol] && 
            grid2[newrow][newcol]){
                dfs(grid1, grid2, newrow, newcol, visited, dxdy, flag);
            }
        } 
        return flag;  
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int dxdy[][4] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        vector<vector<int>> visited(n, vector<int>(m,0));

        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && !visited[i][j]){
                    bool flag = true;
                    if(dfs(grid1, grid2, i, j, visited, dxdy, flag)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
