class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        stack<pair<int, int>> st;
        int n = tem.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                res[i] = 0;
                // st.push({tem[i], i});
            }
            while (!st.empty() && tem[i] >= st.top().first) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = abs(st.top().second - i);
               
            } else {
                res[i] = 0;
            }
             st.push({tem[i], i});
        }
        return res;
    }
};