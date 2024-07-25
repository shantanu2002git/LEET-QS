class Solution {
public:
    void Join(vector<int>& nums, int st, int md, int en) {
        int n1 = md - st + 1;
        int n2 = en - md;

        vector<int> left(n1);
        vector<int> right(n2);

        // Populate the left and right vectors
        for (int i = 0; i < n1; i++)
            left[i] = nums[st + i];
        for (int j = 0; j < n2; j++)
            right[j] = nums[md + 1 + j];

        int i = 0, j = 0, k = st;

        // Merge the left and right vectors back into nums
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }

        // Copy any remaining elements of left
        while (i < n1) {
            nums[k++] = left[i++];
        }

        // Copy any remaining elements of right
        while (j < n2) {
            nums[k++] = right[j++];
        }
    }

    void Break(vector<int>& nums, int st, int en) {
        if (st >= en) {
            return;
        }

        int md = st + (en - st) / 2;
        Break(nums, st, md);
        Break(nums, md + 1, en);
        Join(nums, st, md, en);
    }

    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) {
            return nums;
        }

        int st = 0;
        int en = nums.size() - 1;
        Break(nums, st, en);
        return nums;
    }
};
