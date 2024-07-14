class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int dp[1001][1001][2]={};
        int res=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dp[i][j][0]=(dp[i-1][j][0]+dp[i][j-1][0]-dp[i-1][j-1][0])+(grid[i-1][j-1]=='X');
                dp[i][j][1]=(dp[i-1][j][1]+dp[i][j-1][1]-dp[i-1][j-1][1])+(grid[i-1][j-1]=='Y');

                if(dp[i][j][0]!=0 && dp[i][j][0]==dp[i][j][1]){
                    res++;
                }
            }
        }
        return res;
    }
};