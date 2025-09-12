class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=*min_element(nums.begin(), nums.end());
        int res=0;
        for(auto it : nums){
            res=res+(it-mx);
        }
        return res;
    }
};