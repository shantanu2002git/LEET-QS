class Solution {

public:

long long  caldp(long long n, long long x,long long i,vector<vector<int>>&dp){
    if(n==0){
        return 1;
    }
    if(n<0 || pow(i,x)>n){
        return 0;
    }
    long long  ntt=0,ttk=0;

if(dp[n][i]!=-1){
    return dp[n][i];
}
    ttk=caldp(n-pow(i,x),x,i+1,dp);
    ntt=caldp(n,x,i+1,dp);
   
   long long ways=(ttk+ntt)%(1000000000+7);
    return dp[n][i]=ways;
}
    int numberOfWays(int n, int x) {
       vector<vector<int>>dp(1000,vector<int>(1000,-1));
      return caldp(n,x,1,dp); 
    }
};