class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) { // time complexity is O(m*nlogk), m = nums1 size, n = nums2 size
        priority_queue<pair<int,pair<int,int>>> pq;  // default: the greatest comes top
        for(int i=0;i<nums1.size();i++) {
            for(int j=0;j<nums2.size();j++) {
                int sum=nums1[i]+nums2[j];
                if (pq.size()<k) {
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if (sum<pq.top().first) {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                } else {
                    break; 
                 // save time! since we don't need to traverse the rest of vector 2
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};