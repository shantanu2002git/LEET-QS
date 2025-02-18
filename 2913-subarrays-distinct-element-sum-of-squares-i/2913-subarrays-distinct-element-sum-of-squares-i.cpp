class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            set<int> st;
            for (int j = i; j < n; j++) { 
                // set<int> st;
                
                // for (int l = i; l <= j; l++) {
                            st.insert(nums[j]);
                // }
                
                int m = st.size();
                res += (m * m);
            }
        }
        return res;
    }
};
