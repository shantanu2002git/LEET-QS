class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0; i<n; i++){
            dp[0][i]=mat[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                if(j==0){
                    dp[i][j]=mat[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                }else if(j==n-1){
                    dp[i][j]=mat[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }else{
                    dp[i][j]=mat[i][j]+min(dp[i-1][j],min(dp[i-1][j+1],dp[i-1][j-1]));
                }
            }
        }
int res=INT_MAX;
        for(int c=0; c<n; c++ ){
            res=min(res,dp[n-1][c]);
        }
        return res;
    }
};