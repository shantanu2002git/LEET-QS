class Solution {
public:
    int negative_end(vector<int>& nums, int n) {
        //    return 0;
        int i = 0, j = n, point = -1;
        while (i < j) {
            int md = (i + j) / 2;
            if (nums[md] < 0) {
                point = md;
                // md = i;
                point = i;
                i = md + 1;
            } else {
                // md = j - 1;
                j = md;
            }
        }

        cout << point;
        return -1;
    }

    int posative_start(vector<int>nums, int n){
        int i = 0, j = n, point = -1;
        while (i < j) {
            int md = (i + j) / 2;
            if (nums[md] <= 0) {
                point = md;
                // md = i;
                point = i;
                i = md + 1;
            } else {
                // md = j - 1;
                j = md;
            }
        }

        cout << point;
        return -1;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n, point = -1;

        int neg=negative_end(nums, n);
        int pos=posative_start(nums,n);

        return (neg==-1 && pos==-1) ? n : max(pos);
    }
};