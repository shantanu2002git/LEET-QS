class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        deque<int> q;
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            if(!q.empty() && q.front() < i-k){
                q.pop_front();
            }
            int maxi = dp[q.empty() ? i : q.front()];
            dp[i] = max(nums[i], nums[i] + maxi);
            while(!q.empty() && dp[i] >= dp[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
