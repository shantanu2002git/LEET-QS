class Solution {
public:
     int cal(int idx, int idy,vector<vector<int>>& dp){
    if(idx<0 || idy<0){
        return 0;
    }
    // if(obstacle[idx][idy]==1){
    //     return 0;
    // }
    if(idx==0 && idy==0){
        return 1;
    }
    
    if(dp[idx][idy]!=-1){
        return dp[idx][idy];
    }
   int tp=cal(idx-1,idy,dp);
   int lf=cal(idx,idy-1,dp);

   return dp[idx][idy]=(tp+lf);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,(vector<int>(n+1,-1)));
        return cal(m-1,n-1,dp);
    }
};