class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size(),res=0;
        sort(nums.begin(),nums.end());
        for(int i=n-1; i>=0;i--){
            int lw=0,en=i-1;

            while(lw<en){
                if(nums[lw]+nums[en]>nums[i]){
                    res=res+(en-lw);
                    en--;
                }else{
                    lw++;
                }
            }
            
        }
        return res;
    }
};