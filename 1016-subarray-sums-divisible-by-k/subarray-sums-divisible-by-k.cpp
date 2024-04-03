class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> mp;
        int sum = 0, c = 0, res = 0;
        int n = nums.size();
        mp.insert({0, 1});
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
            int rem = (sum % k + k) % k;
            if (mp.find(rem) != mp.end()) {
                res = res + mp[rem];
                mp[rem]++;
            } else {
                mp.insert({rem, 1});
            }
        }
        return res;
    }
};