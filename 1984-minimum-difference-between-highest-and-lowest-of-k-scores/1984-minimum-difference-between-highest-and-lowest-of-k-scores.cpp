class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size(),mi=1e9;
        for(int i=0; i<=n-k; i++){
            mi=min(mi,abs(nums[i]-nums[i+k-1]));
        }
        return mi;
    }
};

// 1 4 7 9