class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int mx = 0, n = nums.size(),s=0;
        for (int i = 0; i < n; i++) {
            int it = nums[i];
            s += (it == 1) ? +1 : -1;
            if (mp.find(s) != mp.end()) {
                mx = max(i - mp[s], mx);
            } else {
                mp[s] = i;
            }
        }
        return mx;
    }
};