class Solution {
public:
set<vector<int>>st;
void calper(int idx, vector<int>&nums, vector<vector<int>>&res){
    if(idx==nums.size()){
        if(st.find(nums)==st.end()){
            res.push_back(nums);
        }
        st.insert(nums);
        return;
    }

    for(int i=idx; i<nums.size(); i++){
        swap(nums[idx],nums[i]);
        calper(idx+1,nums,res);
        swap(nums[idx],nums[i]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        calper(0,nums,res);
        return res;
    }
};