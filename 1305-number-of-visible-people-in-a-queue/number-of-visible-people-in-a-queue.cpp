class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& hi) {
        stack<int>st;
        int count=0,n=hi.size();
        vector<int>res(n,0);
        st.push(hi[n-1]);
        for(int i=n-2; i>=0; i--){
            int count=0;
            while(!st.empty() && st.top()<hi[i]){
                count++;
                st.pop();
            }
            if(!st.empty()){
                count++;
            }
            st.push(hi[i]);
            res[i]=count;
        }
        return res;
        
    }
};