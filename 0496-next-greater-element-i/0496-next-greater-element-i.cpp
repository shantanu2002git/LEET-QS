class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                mp[nums2[i]] = -1;

            } else {
                while (!st.empty() && nums2[i] > st.top() ) {
                    st.pop();
                }
                if (st.empty()) {
                    mp[nums2[i]] = -1;

                } else {
                    mp[nums2[i]] = st.top();
                }
            }
            st.push(nums2[i]);
        }
        vector<int> res;
        for (int j = 0; j < nums1.size(); j++) {
            res.push_back(mp[nums1[j]]);
        }
        return res;
    }
};