class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int mx = -1e9, mi = 1e9, difs = 0;
            for (int j = i; j < n; j++) {
                mx = max(mx, nums[j]);
                mi = min(mi, nums[j]);
                cout << i<<" "<<mx << " " << mi << nums[i]<<endl;
                difs = mx - mi;
                res = res + difs;
            }
        }
        return res;
    }
};