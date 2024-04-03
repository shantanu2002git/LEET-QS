class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int s = 0,n=nums.size(),res=0;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            s = s + nums[i];
            // mp[s]++;
            if (s == k) {
                res++;
            }
            if (mp.find(s - k) != mp.end()) {
                res = res + mp[s - k];
            }
            mp[s]++;
        }
        return res;
    }
};