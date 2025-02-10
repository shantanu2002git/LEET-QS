class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (!st.empty() && '0' <= s[i] && s[i] <= '9') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};
