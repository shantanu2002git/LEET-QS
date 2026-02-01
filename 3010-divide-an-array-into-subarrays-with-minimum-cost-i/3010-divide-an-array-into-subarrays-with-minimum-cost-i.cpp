class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // sort(nums.begin()+1, nums.end());
        int n1 = 100, n2 = 100, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < n1) {
                   n2=n1;
                n1 = nums[i];
            }
           else if ( nums[i]<n2 ) {
                n2 = nums[i];
            }
        }
        cout<<nums[0]<<" "<<n1<<" "<<n2;
        return nums[0] + n1 + n2;
    }
};