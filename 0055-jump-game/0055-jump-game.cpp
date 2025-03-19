class Solution {
public:
int caldp(int idx, int n, vector<int>&arr, vector<int>&dp){
    if(idx==n){
          return 0;
      }
      if(dp[idx]!=-1){
          return dp[idx];
      }
      int jmp=1e9;
      for(int i=arr[idx]; i>=1; i--){
          if(idx+i<=n){
              jmp=min(jmp,1+caldp(idx+i,n,arr,dp));
          }
      }
      return dp[idx]=jmp;
}
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
          int n =nums.size() - 1;
	vector<int>dp(n,-1);
    //return caldp(0,n,nums,dp)!=1e9;
    int next=0;
    int mxjp=0;
    int jumps=0;
  
    for(int i=0; i<n; i++){
        mxjp=max(mxjp,nums[i]+i);
        if(i==next){
            jumps++;
            if(next==mxjp){
                return 0;
            }
            next=mxjp;
        }
    }

    return jumps;
    }
};

//https://www.youtube.com/watch?v=wLPdkLM_BWo