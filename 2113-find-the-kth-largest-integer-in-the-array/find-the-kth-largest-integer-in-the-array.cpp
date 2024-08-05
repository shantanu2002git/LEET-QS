class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [&](string& a, string& b) {
            return (a.size() == b.size() ? a < b : a.size() < b.size());
        });
        int n = nums.size();
        return nums[n - k];
    }
};