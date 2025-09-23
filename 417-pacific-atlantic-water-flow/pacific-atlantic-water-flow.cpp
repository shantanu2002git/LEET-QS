class Solution {
public:
    void dfs(int x, int y, int n, int m, int pvx, int pvy,
             vector<vector<bool>>& vis, vector<vector<int>>& hi) {
        if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y])
            return;

        if (pvx >= 0 && pvy >= 0 && hi[pvx][pvy] > hi[x][y])
            return;

        vis[x][y] = 1;
        dfs(x + 1, y, n, m, x, y, vis, hi);
        dfs(x - 1, y, n, m, x, y, vis, hi);
        dfs(x, y + 1, n, m, x, y, vis, hi);
        dfs(x, y - 1, n, m, x, y, vis, hi);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& hi) {
        int n = hi.size(), m = hi[0].size();
        vector<vector<bool>> vispc(n, vector<bool>(m)), visac(n, vector<bool>(m));
        /* Pacific Ocean*/
        /*left*/
        for (int rw = 0; rw < n; rw++) {
            dfs(rw, 0, n, m, -1, -1, vispc, hi);
        }
        /* top*/
        for (int cl = 0; cl < m; cl++) {
            dfs(0, cl, n, m, -1, -1, vispc, hi);
        }

        /* Atlantic Ocean*/
        /*right*/
        for (int rw = 0; rw < n; rw++) {
            dfs(rw, m - 1, n, m, -1, -1, visac, hi);
        }
        /*bottom*/
        for (int cl = 0; cl < m; cl++) {
            dfs(n - 1, cl, n, m, -1, -1, visac, hi);
        }

        vector<vector<int>>res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vispc[i][j] && visac[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};