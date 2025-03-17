class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,n1=nums1.size(),n2=nums2.size();
        set<int>st;
       sort(nums1.begin(),nums1.end());
       sort(nums2.begin(),nums2.end());
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                i++;
            }
            if(nums1[i]>nums2[j]){
                j++;
            }
            else if(nums1[i]==nums2[j]){
                st.insert(nums1[i]);
                i++;j++;
            }
        }
 vector<int>vc(st.begin(),st.end());
 return vc;
    }
};