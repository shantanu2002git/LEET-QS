class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n), prf(n), suf(n);
        prf[0]=nums[0];
        suf[n-1]=nums[n-1];

        for(int i=1; i<n; i++){
            prf[i]=prf[i-1]+nums[i];
            suf[n-i-1]=suf[n-i]+nums[n-i-1];
        }

        for(int i=0; i<n; i++){
            int vl=nums[i], it;
             it=((vl*i)-prf[i])+(suf[i]-(vl*(n-1-i)));
            res[i]=it;
        }

        return res;

    }
};