class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {

            int stidx = lower_bound(nums.begin() + i + 1, nums.end(), lower-nums[i]) - nums.begin();
            int enidx = upper_bound(nums.begin() + i + 1, nums.end(), upper-nums[i]) - nums.begin();
            cout<<stidx<<" "<<enidx<<endl;
            res = res + (enidx - stidx);
        }
        return res;
    }
};
