class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n=nums.size();
        int lw=0,hi=n-1;
        while(lw<=hi){
            int md=(lw+hi)/2;

            if(nums[md]==t){
                return md;
            }
            if(nums[lw]<=nums[md]){
                if(nums[lw]<=t && t<=nums[md]){
                    hi=md-1;
                }else{
                    lw=lw+1;
                }
            }
            else{
                if(nums[md]<=t && t<=nums[hi]){
                    lw=md+1;
                }else{
                    hi=md-1;
                }
            }
        }
        return -1;
    }
};