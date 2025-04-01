class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (auto it : tokens) {
            if (it == "+" || it == "-" || it == "*" || it == "/") {
                int n1 = st.top(); st.pop();
                int n2 = st.top(); st.pop();

                if (it == "+") st.push(n2 + n1);
                else if (it == "-") st.push(n2 - n1);
                else if (it == "*") st.push(n2 * n1);
                else st.push(n2 / n1);  

            } else {
                st.push(stoi(it));  
            }
        }
        
        return st.top();
    }
};
