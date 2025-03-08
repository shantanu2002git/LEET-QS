

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        map<int, int> mp;

        // Merge nums1 into the map
        for (auto& it : nums1) {
            mp[it[0]] += it[1];
        }

        // Merge nums2 into the map
        for (auto& it : nums2) {
            mp[it[0]] += it[1];
        }

        // Create the result vector from the map
        for (auto& it : mp) {
            res.push_back({it.first, it.second});
        }

        return res;
    }
};
