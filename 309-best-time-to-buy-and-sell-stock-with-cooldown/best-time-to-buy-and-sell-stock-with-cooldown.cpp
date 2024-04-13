class Solution {
public:
int call(int i , int by, int n, vector<int>&p,vector<vector<int>>&dp){
if(i>=n){
    return 0;
}
if(dp[i][by]!=-1){
    return dp[i][by];
}

int mx1=0,mx2=0;
if(by==1){
    mx2=max(-p[i]+call(i+1,0,n,p,dp),0+call(i+1,1,n,p,dp));
}else{
    mx2=max(+p[i]+call(i+2,1,n,p,dp), 0+call(i+1,0,n,p,dp));
}
return dp[i][by]=mx2;

}
    int maxProfit(vector<int>& p) {
       int n=p.size();
       vector<vector<int>>dp(n+1,vector<int>(2,-1));
       return call(0,1,n,p,dp); 
    }
};