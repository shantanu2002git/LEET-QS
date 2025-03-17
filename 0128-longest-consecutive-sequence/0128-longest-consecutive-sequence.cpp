class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        map<int, int> fq;
        
        for (int i = 0; i < n; i++) {
            fq[nums[i]]++;
        }
        
        int mx = 0, cnt = 0;
        int prev = INT_MIN;
        
        for (auto it : fq) {
            if (it.first == prev + 1) {
                cnt++;
            } else {
                cnt = 1; 
            }
            mx = max(mx, cnt);
            prev = it.first; 
        }
        
        return mx;
    }
};
