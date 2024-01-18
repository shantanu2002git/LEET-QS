class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),j=0,i=0,s=0,mx=1e9;
        for(int i=0; i<n;i++){
               s=s+nums[i];
               while(s>=target){
                   mx=min(mx,(i-j+1));
                   s=s-nums[j];
                   j++;
               }
        }
        return mx==1e9 ? 0 : mx;
    }
};