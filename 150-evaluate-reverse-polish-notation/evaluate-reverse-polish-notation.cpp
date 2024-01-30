class Solution {
public:
    bool valid(string si) {
        return (si == "+" || si == "-" || si == "*" || si == "/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto it : tokens) {

            if (valid(it)) {
                int vl1 = st.top();
                st.pop();
                int vl2 = st.top();
                st.pop();

                if (it == "+") {
                    st.push(vl1 + vl2);
                } else if (it == "-") {
                    st.push(vl2 - vl1);
                } else if (it == "*") {
                    st.push(vl1 * vl2);
                } else {
                    st.push(vl2 / vl1);
                }
            }

            else {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};