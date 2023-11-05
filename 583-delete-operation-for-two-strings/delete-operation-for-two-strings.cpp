class Solution {
public:
    int caldp(string w1, string w2, int idx1, int idx2, vector<vector<int>>&dp){
        if(idx1<0 || idx2<0){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(w1[idx1]==w2[idx2]){
         return   dp[idx1][idx2] = 1+caldp(w1,w2,idx1-1,idx2-1,dp);
        }
  dp[idx1][idx2] =max(caldp(w1,w2,idx1-1,idx2,dp), caldp(w1,w2,idx1,idx2-1,dp));
        
        return dp[idx1][idx2];
    }
    
    int minDistance(string w1, string w2) {
        int n1=w1.size(),n2=w2.size();
        vector<vector<int>>dp(n1+1,(vector<int>(n2+1,-1)));
        return n1+n2-2*caldp(w1,w2,n1-1,n2-1,dp);
    }
};
