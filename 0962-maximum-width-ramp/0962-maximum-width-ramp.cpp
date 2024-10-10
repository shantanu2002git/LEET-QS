class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;


        // Store indices of elements in a stack
        for (int i = 0; i < n; i++) {

            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
            
        }

        int max_width = 0;

        // Traverse from the end to the start 
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                max_width = max(max_width, j - st.top());
                st.pop();
            }
        }


        return max_width;
    
    }
};
