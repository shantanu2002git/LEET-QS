class Solution {
    
int cal2_dp(int idx, int bol, int n , vector<int>& points, vector<vector<int>>&dp){
    if(idx==n){
        return 0;
    }
    if(dp[idx][bol]!=-1){
        return dp[idx][bol];
    }
    int prfi=0;
    if(bol){ // FOR BUY - TTK OR NOT NTT
    prfi=max(-points[idx]+cal2_dp(idx+1,0,n,points,dp), 0+cal2_dp(idx+1,1,n,points,dp));
    }else{
        //FOR SELL - SELL OR NOT SELL
        prfi=max(+points[idx]+cal2_dp(idx+1,1,n,points,dp),cal2_dp(idx+1,0,n,points,dp));
    }
    return dp[idx][bol]=prfi; 
}
    
public:
    int maxProfit(vector<int>& points) {


int n= points.size();
        vector<vector<int>>dp(n,(vector<int>(2,-1)));
       return cal2_dp(0,1,n,points,dp);
    

    /*
    \U0001f494\U0001f494\U0001f494SEE THE QUESTION CAREFULLY THEY ONLY SAY TO MAXIMIZE THE PROFIT ---
    NOT SAYING THAT WITH MINIMUM STEP;\U0001f525\U0001f525\U0001f525
       // vector<int>pf;
        int s=0;
        for(int i=0; i<prices.size()-1; i++){
            if(prices[i]<prices[i+1]){
               s+=(prices[i+1]-prices[i]); //T.C O(n) S.C O(1)
               //pf.push_back(prices[i+1]-prices[i])  T.C O(n) S.C O(n)
            }
        }
       // int res=accumulate(pf.begin(),pf.end(),0);
        return s;
        */
    }
};