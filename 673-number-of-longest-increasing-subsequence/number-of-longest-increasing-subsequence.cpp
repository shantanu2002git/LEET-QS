class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int maxi = 1;
        int n = arr.size();
        vector<int>dp(n,1) , cnt(n,1);

        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < i ; j++){
                if(arr[i] > arr[j] && dp[j] + 1 > dp[i]){
                    dp[i] = 1+ dp[j];
                    //inherit
                    cnt[i] = cnt[j];
                }
                else if(arr[j] < arr[i] && 1+dp[j] == dp[i]){
                    //increase count
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi , dp[i]);
        } 
        int nos = 0;
        for(int i = 0 ; i < n ; i++){
            if(dp[i] == maxi)
                nos += cnt[i];
        }
        return nos;
    }
};