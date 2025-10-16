class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
      int inc=1,n=nums.size();
     vector<int>ins;
      for(int i=1; i<n; i++){
         if(nums[i-1]<nums[i]){
            inc++;
         }
         else{
            ins.push_back(inc);
            // cout<<inc<<" ";
            inc=1;
         }
      }
ins.push_back(inc);
int res=0;

for(auto it : ins){
    cout<<it<<" ";
}
      cout<<endl;

for(int i=0; i<ins.size()-1; i++){
    int a=ins[i],b=ins[i+1];
 res=max(res,max((max(a,b))/2, min(a,b)));
    cout<<ins[i]<<" "<<ins[i+1]<<endl;
}
  
      return (ins.size()==1) ? ins[0]/2 : res;
    }
};