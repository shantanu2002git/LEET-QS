class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n=nums.size(),mx=-1,s=0,mn=-1e9;
    for(int i=0; i<n; i++){
        s=s+nums[i];
        if(s>mx){
            mx=max(mx,s);
        }
        else if(s<=0){
            s=0;
        }
        mn=max(mn,nums[i]);
    }
    return max(mx,s)==0 ? mn : max(mx,s);
    }
};