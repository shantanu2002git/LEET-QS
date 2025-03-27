class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmx_prefix(n, 0);
        vector<int> rightmin_sufix(n, 0);

    
        leftmx_prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftmx_prefix[i] = max(leftmx_prefix[i - 1], nums[i]);
        }

       
        rightmin_sufix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmin_sufix[i] = min(rightmin_sufix[i + 1], nums[i]);
        }

     
        for (int i = 1; i < n; i++) {  
            if (leftmx_prefix[i - 1] <= rightmin_sufix[i]) {
                return i;  // Return partition index
            }
        }
        
        return -1; 
    }
};
