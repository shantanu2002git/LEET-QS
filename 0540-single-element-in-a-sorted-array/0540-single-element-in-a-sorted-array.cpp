class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res=0;
        for(auto it : nums){
            res=res^it;
        }
        return res;
    }
};