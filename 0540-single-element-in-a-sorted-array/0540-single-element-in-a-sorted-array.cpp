class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
       
        /*
        understanding this problem with the EVEN-ODD indexing and try to element basis on thois
        1. even-odd + target + odd-even it will reverse as left part and right part of target
        */

        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
         int lf=1,rg=n-2;
        while(lf<=rg){
            int md=(lf+rg)/2;

            if(nums[md]!=nums[md-1] && nums[md]!=nums[md+1]){
                return nums[md];
            }


            /*EVEN-ODD :|or|: ODD-EVEN*/

            if((md%2==0 && nums[md]==nums[md+1]) || (md%2==1 && nums[md]==nums[md-1])){
                lf=md+1;
            }else{
                rg=md-1;
            }
          
        }
        return -1;
    }
};