class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n=tem.size();
        vector<int>res(n,0);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && tem[i]>tem[st.top()]){
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;

    }
};