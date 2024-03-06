class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int s = 0;
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        while(k--){
            int tp=pq.top();
            pq.pop();
            pq.push(-1*tp);
        }
        int res=0;
        while(!pq.empty()){
            res=res+pq.top();
            pq.pop();
        }
        return res;
    }
};