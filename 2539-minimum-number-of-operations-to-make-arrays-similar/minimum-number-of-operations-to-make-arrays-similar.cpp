class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long s = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        vector<int> evn, evt, odn, odt;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                evn.push_back(nums[i]);
            } else if (nums[i] % 2 != 0) {
                odn.push_back(nums[i]);
            }

            if (target[i] % 2 == 0) {
                evt.push_back(target[i]);
            } else if (target[i] % 2 != 0) {
                odt.push_back(target[i]);
            }
        }
        for (int i = 0; i < evn.size(); i++) {
            s = s + abs((evn[i] - evt[i])) / 2;
        }
        for (int i = 0; i < odn.size(); i++) {
            s = s + abs((odn[i] - odt[i])) / 2;
        }
        return s / 2;
    }
};