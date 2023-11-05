class Solution {
public:

    int f(int ind,vector<int>& sum,vector<int>& dp){ 
            
        if(ind==0) return sum[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int ttk=sum[ind]+f(ind-2,sum,dp);
        int ntt=0+f(ind-1,sum,dp);

        return dp[ind]=max(ttk,ntt);
    }
    int deleteAndEarn(vector<int>& nums){
        int n = 10001;
        vector<int> sum(n, 0);
        for(auto num: nums){
            sum[num]+=num;
        }
        vector<int> dp(n, -1);
        int m=sum.size();
        return f(m-1,sum,dp);
    }
};
