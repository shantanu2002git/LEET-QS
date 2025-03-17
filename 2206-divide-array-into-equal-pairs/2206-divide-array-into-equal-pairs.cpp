class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        for (auto it : mp) {
            if ((it.second % 2) != 0) {
                return false;
            }
        }
        return true;
    }
};