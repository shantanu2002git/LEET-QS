class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        for (auto it : op) {
            // nums[mp[it[0]]] = it[1];
            // mp[it[1]]=mp[it[0]];
            int ix;
            if(mp.find(it[0])!=mp.end()){
                ix=mp[it[0]];
                nums[mp[it[0]]]=it[1];
            }
            mp[it[1]]=ix;
        }
        return nums;
    }
};