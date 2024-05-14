class Solution {
public:
set<vector<int>>st;
void calper(int st, vector<int>&nums, vector<vector<int>>&res){
    if(st==nums.size()){
        // if(st.find(nums)==st.end()){
            res.push_back(nums);
        // }
        // st.insert(nums);
        return;
    }

    for(int i=st; i<nums.size(); i++){
         bool found = false;
        for (int j = st; j < i; j++)
        {
            if (nums[i] == nums[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            swap(nums[st], nums[i]);
            calper(st+1,nums,res);
            swap(nums[st], nums[i]);
        }
       
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        calper(0,nums,res);
        return res;
    }
};