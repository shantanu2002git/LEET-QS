class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prf=1,suf=1, n=nums.size(),mx=INT_MIN;
        for(int i=0; i<n; i++){
            if(prf==0) prf=1;
            if(suf==0) suf=1;
            prf=prf*nums[i];
            suf=suf*nums[n-i-1];
            mx=max(mx,max(prf,suf));
        }
        return mx;
    }
};