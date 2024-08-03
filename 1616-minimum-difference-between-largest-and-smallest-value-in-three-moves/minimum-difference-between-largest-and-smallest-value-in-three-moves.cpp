class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(), mini = INT_MAX;
        if (n <= 4) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int lef=0,rig=(n-1)-3;
        while(lef<4 && rig<n){
            mini=min(mini,nums[rig]-nums[lef]);
            lef++;
            rig++;
        }
       // mini = min(abs(nums[n - 1] - nums[3]), abs(nums[n - 3 - 1] - nums[0]));
        return mini;
    }
};