class Solution {
public:

    void bfs(queue<pair<int,int>> &q, vector<vector<bool>> &vis, vector<vector<int>>& heights, int n, int m)
    {
        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, -1, 0, 1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[r][c] = true; // mark visited

            for(int i=0;i<4;i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i]; // ********?????????
                if(nr >=0 && nr < n && nc >=0 && nc < m && heights[r][c] <= heights[nr][nc] && !vis[nr][nc]) {
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m)); // visited array
        vector<vector<bool>> atl(n, vector<bool>(m));
        queue<pair<int,int>>q;

        // push cells connected to pacific ocean
        for(int i=n-1;i>=0;i--) q.push({i, 0}); // first col 
        for(int i=m-1;i>=0;i--) q.push({0, i}); // first row

        bfs(q, pac, heights, n, m);
        for(auto it : pac){
            for(auto l : it)
            {
                cout<<l << " ";
            }
            cout<<endl;
        }
        cout<<endl;

        // push cells connected to atlantic ocean
        for(int i=n-1;i>=0;i--) q.push({i, m-1}); // last col
        for(int i=m-1;i>=0;i--) q.push({n-1, i}); // last row

        bfs(q, atl, heights, n, m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};

/*
Pacific Atlantic Water Flow Logic

Water flow rule:

Water can flow from a cell to a neighboring cell if the neighbor's height is less than or equal to the current cell.

Formally: water can go from (r,c) → (nr,nc) if heights[nr][nc] <= heights[r][c].

Our BFS approach:

Instead of simulating water flowing from each cell to the ocean, we do BFS starting from the oceans and move backwards.

This way, any cell reached in BFS is a cell from which water can eventually reach the ocean.

Why we reverse the inequality:

Suppose we are at cell (r,c) that is already known to reach the ocean.

To find which neighbors can also reach the ocean, we can only move to neighbors that are ≥ current height, because water can flow from higher → lower, but not from lower → higher.

So in BFS from ocean, the neighbor (nr,nc) must satisfy:

heights[nr][nc] >= heights[r][c]


This ensures that if water is at (nr,nc), it can eventually flow to (r,c) → and since (r,c) can reach the ocean, (nr,nc) can also reach it.

*/