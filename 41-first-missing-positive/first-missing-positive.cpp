class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (auto it : nums) {
            mp[it] = 1;
        }
        int mx=*max_element(nums.begin(),nums.end());

        for (int i=1; i<=abs(mx); i++) {
           
            if (mp.find(i) == mp.end()) {
                return i;
            }
        }
        return mx+1;
    }
};