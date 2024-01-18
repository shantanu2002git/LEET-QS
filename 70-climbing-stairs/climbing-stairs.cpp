class Solution {
public:
int call(int n, vector<int>&dp){
    if(n==0){
        return 1;
    }else if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int t1,t2;
    t1=call(n-1,dp);
    
    if(n>1){
    t2=call(n-2,dp);
    }

    return dp[n]=(t1+t2);
}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return call(n-1,dp);
    }
};