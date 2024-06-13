class Solution {
public:
int call(int idx, int ts, int n , vector<int>&rew, vector<vector<int>>&dp ){
    if(idx==n){
        return ts;
    }
    if(dp[idx][ts]!=-1){
        return dp[idx][ts];
    }

    int in=0,ex=0;
    if(rew[idx]>ts){
        in=call(idx+1,ts+rew[idx], n, rew, dp);
    }
    ex=call(idx+1, ts, n, rew, dp);
    return dp[idx][ts]=max(in,ex);
}
    int maxTotalReward(vector<int>& rew) {
        sort(rew.begin(),rew.end());
        int n=rew.size();
        vector<vector<int>>dp(2001,vector<int>(4001,-1));
        return call(0,0,n,rew,dp);
    }
};