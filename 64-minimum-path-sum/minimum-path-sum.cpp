class Solution {
public:
int call(int rw, int cl, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp ){
    if(rw==n-1 && cl==m-1){
        return grid[rw][cl];
    }
    else if(rw<0 || cl<0 || rw>=n || cl>=m){
        return 1e9;
    }

    if(dp[rw][cl]!=-1){
        return dp[rw][cl];
    }

    int dw=call(rw+1,cl,n,m,grid,dp);
    int rdw=call(rw,cl+1,n,m,grid,dp);

    return dp[rw][cl]=grid[rw][cl]+min(dw,rdw);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return call(0,0,n,m,grid,dp);
    }
};