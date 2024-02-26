#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                st.top().second++; 
                if (st.top().second == k) {
                    st.pop(); 
                }
            } else {
                st.push({c, 1}); 
            }
        }
        string result = "";
        while (!st.empty()) {
            // Append characters from the stack to the result
            result = string(st.top().second, st.top().first) + result;
            st.pop();
        }
        return result;
    }
};
