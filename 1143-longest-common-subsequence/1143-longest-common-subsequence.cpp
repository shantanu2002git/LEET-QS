class Solution {
public:
    int call(string &text1, string &text2,int m,int n,vector<vector<int>>&dp) {
        if(m==0 || n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return dp[m][n]= 1+call(text1,text2,m-1,n-1,dp);
        }else{
            return dp[m][n]= max(call(text1,text2,m-1,n,dp),call(text1,text2,m,n-1,dp));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(1001,(vector<int>(1001,-1)));
        return call(text1,text2,m,n,dp);
    }
};