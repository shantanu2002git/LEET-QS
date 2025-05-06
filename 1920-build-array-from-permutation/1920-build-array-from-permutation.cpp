class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
      int n=nums.size();
      vector<int>vc;
        for(int i=0; i<n; i++){
          vc.push_back(nums[nums[i]]);
        }
        return vc;
    }
};