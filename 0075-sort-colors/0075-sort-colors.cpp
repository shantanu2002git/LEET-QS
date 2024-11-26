class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p2 = n - 1, p1, p0 = 0;

        for (int i = 0; i <= p2; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[p2]);
                i--;
                p2--;
            }
        }
        
    }
};