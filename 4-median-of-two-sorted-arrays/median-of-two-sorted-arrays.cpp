
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vc;
        int n1=nums1.size(),n2=nums2.size();
        int i=0,j=0;
      
        while(i<n1 && j<n2) {
        if(nums1[i]<=nums2[j]) {
            vc.push_back(nums1[i]);
        i++;
        }   
        else if(nums1[i]>=nums2[j]) {
        vc.push_back(nums2[j]);
        j++;
        }   
        
    }
   
    if(i<n1){
        for(int k1=i; k1<n1; k1++){
            vc.push_back(nums1[k1]);
        }
    }
    if(j<n2){
        for(int k2=j; k2<n2; k2++){
            vc.push_back(nums2[k2]);
        }
    }
   
int n=vc.size();
int nw=n-1;
return (n%2==0) ? (vc[nw/2]+vc[nw/2+1])/2.0 : (vc[nw/2]);

    }
};