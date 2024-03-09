class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        for (int i = 0; i < n; i++) {
            int vl = nums1[i];
            int l = 0, r = m-1;
            while (l <= r) {
                int md = (l + r) / 2;
                if (nums2[md] == vl) {
                    return nums1[i];
                  
                }
                if (vl < nums2[md]) {
                    r = md - 1;
                } else {
                    l = md + 1;
                }
              
            }
        }
        return -1;
    }
};