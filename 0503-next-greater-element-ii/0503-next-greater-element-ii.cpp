class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);  // Initialize result with -1
        stack<int> st;

        // Simulate circular traversal: from 2n - 1 to 0
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;

            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            if (i < n) { // Only fill result in the first pass
                if (!st.empty()) {
                    res[idx] = st.top();
                }
            }

            st.push(nums[idx]); // Push current element for future comparisons
        }

        return res;
    }
};
