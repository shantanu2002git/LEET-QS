class Solution {
public:
    string simplifyPath(string p) {
        stack<string>st;

        for(int i=0; i<p.size(); i++){
            if(p[i]=='/'){
                continue;
            }
            string si="";
            while(i<p.size() && p[i]!='/'){
                si=si+p[i];
                i++;
            }
            if(si=="."){
                continue;
            }
            else if(si==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(si);
            }
        }
        string res;

        while(!st.empty()){
            res="/"+st.top()+res;
            st.pop();
        }
        return (res.size()==0)  ? "/" : res;
    }
};