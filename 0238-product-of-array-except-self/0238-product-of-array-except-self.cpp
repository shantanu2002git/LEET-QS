class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>vc(n,0);
        bool fl=0;
        int mul=1,zr=0;
        for(int i=0; i<n;i++){
        if(nums[i]!=0){
            mul=mul*nums[i];
        }else if(nums[i]==0){
            zr++;
            fl=1;
        }
        }
        if(zr>1){
            return vc;
        }
        else  if(zr){
        for(int i=0; i<n; i++){
            if(nums[i]==0 )
               vc[i]=(mul);
        }
        }else{
          for(int i=0; i<n; i++){
           
               vc[i]=(mul/nums[i]);
        }
        }
        return vc;
    }
};