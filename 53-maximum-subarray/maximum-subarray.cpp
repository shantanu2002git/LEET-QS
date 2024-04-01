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
/*
class Solution {
public:  
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int sum = nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            sum = max(sum + nums[i], nums[i]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};

*/