class Solution {
public: /*Question : Return the fewest number of coins that you need to make up that amount*/
int call(int i, int n, int t, vector<int>&con,  vector<vector<int>>&dp ){
    if(t==0){
        return 0;
    }
    if(i>=n || t<0)
    {
        return 1e9;
    }
    if(dp[i][t]!=-1)
    {
        return dp[i][t];
    }
    int tt=-1e9,nn=-1e9;
    tt=1+call(i,n,t-con[i],con,dp);
    nn=call(i+1,n,t,con,dp);

    return  dp[i][t]=min(tt,nn);
}

    int coinChange(vector<int>& coins, int am) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(am+1,-1));
        return call(0,n,am,coins,dp)==1e9 ? -1 : call(0,n,am,coins,dp) ;
    }
};