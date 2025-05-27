class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int  len =nums.size();
        if (target > nums[len - 1]) {
            return len;
        }
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        // here left == right, you can return either one
        return right;
    }
};