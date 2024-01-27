class Solution {
public:
int call(int n1, int n2, string wd1, string wd2, vector<vector<int>>&dp){
if(n1<0  || n2<0){
    return 0;
}

int tt=0,nnt=0;
if(dp[n1][n2]!=-1){
    return dp[n1][n2];
}
if(wd1[n1]==wd2[n2]){
    tt=1+call(n1-1,n2-1,wd1,wd2,dp);
}else {
    nnt=max(call(n1-1,n2,wd1,wd2,dp),call(n1,n2-1,wd1,wd2,dp));
}
return dp[n1][n2]=max(tt,nnt);
}
    int minDistance(string wd1, string wd2) {
        int n=wd1.size(),m=wd2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return (n+m)-2*call(n-1,m-1,wd1,wd2,dp);
    }
};