class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size(),c=0;
        stack<char>st;
     
        for(int i=0; i<n; i++){
         if(s[i]=='('){
             st.push('(');
         }  
         else{
             if(!st.empty()){
                 st.pop();
             }else{
                 c++;
             }
         }
        }
        return c+st.size();
    }
};