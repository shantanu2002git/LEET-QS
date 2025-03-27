class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int, int> mp;
        int mxcout = 0, val;
        for (auto i : nums) {
            mp[i]++;
        }
        int n = nums.size();
        map<int, int> pfmp;
        for (int i = 0; i < n; i++) {
            pfmp[nums[i]]++;
            int part1 = pfmp[nums[i]];
            int part2 = mp[nums[i]] - part1;
            cout << i << " " << nums[i] << " " << part1 << " " << part2 << endl;
            if (part1 * 2 > (i + 1) && part2 * 2 > (n - i-1)) {
                return i;
            }
        }

        return -1;
    }
};