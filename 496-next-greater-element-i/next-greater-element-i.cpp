class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size(),mx=-1;
        map<int,int>mp;
        stack<int>st;
        for(int i=n-1; i>=0; i--){
          while(!st.empty() && st.top()<nums2[i]){
              st.pop();
          }

          if(st.empty()){
              mp[nums2[i]]=-1;
          }
          else{
              mp[nums2[i]]=st.top();
          }
          st.push(nums2[i]);
        }
vector<int>res;
        for(auto it : nums1){
res.push_back(mp[it]);
        }
        return res;

    }
};