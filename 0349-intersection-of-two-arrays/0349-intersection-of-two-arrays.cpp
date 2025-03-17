class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        vector<int> res;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                i++;
            }
           else if (nums1[i] > nums2[j]) { 
                j++;
            } 
            else { // nums1[i] == nums2[j]
                if (res.empty() || res.back() != nums1[i]) {
                    res.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return res;
    }
};