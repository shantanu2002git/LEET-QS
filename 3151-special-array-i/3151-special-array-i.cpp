class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        for(int i=0; i<nums.size()-1; i++){
            cout<<nums[i]<<" "<<nums[i+1]<<endl;
            if((nums[i]%2)==(nums[i+1]%2)){
                return false;
            }
        }
        return 1;
    }
};