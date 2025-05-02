class Solution {
public:
    int caldp(int idx, int n, vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(idx*idx>n || n<0){
            return 1e9;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ttk,ntt;
        if(idx*idx<=n){
            ttk=1+caldp(idx,n-(idx*idx),dp);  
        }
        ntt=caldp(idx+1,n,dp);
        return dp[n]=min(ttk,ntt);
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return caldp(1,n,dp); 
    }
};
