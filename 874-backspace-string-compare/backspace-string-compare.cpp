class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size(),m=t.size();
        string si1="",si2="";
        for(int i=0; i<n; i++){
            if(s[i]=='#' && !si1.empty()){
                si1.pop_back();
                continue;
            }
            if(s[i]>='a' && s[i]<='z'){

si1.push_back(s[i]);
            }
        }

        for(int i=0; i<m; i++){
            if(t[i]=='#' && !si2.empty() ){
                si2.pop_back();
                continue;
            }
if(t[i]>='a' && t[i]<='z'){
si2.push_back(t[i]);
            }
        }
cout<<si1<<" "<<si2;
        return si1==si2;
    }
};