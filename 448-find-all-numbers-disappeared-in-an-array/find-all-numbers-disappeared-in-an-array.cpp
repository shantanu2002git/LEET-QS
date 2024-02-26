class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
        Most importent line is : nums of n integers where nums[i] is in the range [1, n]
        */
        vector<int>res;
        int n=nums.size();
        for(int i=0; i<n; i++){
            int idx=abs(nums[i])-1;
            if(nums[idx]>0){
                nums[idx]=-nums[idx];
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};