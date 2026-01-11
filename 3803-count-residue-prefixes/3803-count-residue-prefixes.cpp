class Solution {
public:
    int residuePrefixes(string s) {
        set<char>st;
        int len=1, res=0;
        for(auto i : s){
            st.insert(i);
            if(len%3==st.size()) res++;
            len++;
        }
        return res;
    }
};