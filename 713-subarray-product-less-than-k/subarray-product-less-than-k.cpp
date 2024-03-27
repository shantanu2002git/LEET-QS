class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long n=nums.size(),l=0,r=0,c=0,mul=1;
        while(r<n){
            mul=mul*nums[r];
            while(mul>=k && l<n){
                mul=mul/nums[l];
                l++;
            }
            if(mul<k){
                c=c+(r-l)+1;
            }
            r++;
        }
        if(k==1){
            return 0;
        }
        return c;
    }
};