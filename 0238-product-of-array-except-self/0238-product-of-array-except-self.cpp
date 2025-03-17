class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int, int> mp;
        long long mul = 1;
        for (auto it : nums) {
            mp[it]++;
            if (it == 0)
                continue;
            mul = mul * it;
        }
        int n = nums.size();
        vector<int> res(n, 0);
        if (mp[0] >= 2) {
            return res;
        }

        cout << (mul) << " ";
        for (int i = 0; i < n; i++) {

            if (mp[0] == 1) {
                if (nums[i] == 0) {
                    res[i] = (mul);
                    continue;
                }

                res[i] = 0;
            } else {
                 res[i] = mul/nums[i];
            }
        }
        return res;
    }
};