class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size(), bal=0;
        string res="";
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                if(bal>0){
                    res=res+'(';
                }
                bal++;
            }else{
                bal--;
                if(bal>0){
                    res=res+')';
                }
            }
        }
        return res;
    }
};