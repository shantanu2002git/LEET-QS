class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int np = part.size(), ns = s.size();
        
        for (int i = 0; i < ns; i++) {
            st.push(s[i]);
            if (st.size() >= np) {
                string temi = "";
                for (int j = 0; j < np; j++) {
                    temi = st.top() + temi;
                    st.pop();
                }
                if (temi != part) {
                    for (char c : temi) {
                        st.push(c);
                    }
                }
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
