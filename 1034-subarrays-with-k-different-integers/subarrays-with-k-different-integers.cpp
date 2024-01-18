class Solution {
public:
int call(vector<int>& nums, int k){
      int n=nums.size(),i=0,j=0,c=0;
        map<int,int>mp;
        while(i<n){
            mp[nums[i]]++;
         
              while(mp.size()>k){
                  mp[nums[j]]--;
                  if(mp[nums[j]]==0){
                      mp.erase(nums[j]);
                  }
                  j++;
              }
           c=c+(i-j+1);
           i++;
        }
        return c;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return call(nums,k)-call(nums,k-1);
    }
};