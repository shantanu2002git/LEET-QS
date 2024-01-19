class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>store=nums;
       sort(nums.begin(),nums.end());
       int st=0,en=nums.size()-1;
       while(st<=en && store[st]==nums[st]){
           st++;
       }
       while(en>=0 && store[en]==nums[en]){
           en--;
       }

       return (st>en || en<0) ? 0 : (abs(en-st+1));
    }
};