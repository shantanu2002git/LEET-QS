class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        int i=0,j=0;
        while(i<n){
            if(s[i]==s[i+1]){
                int adj=i+1;
                int nxt=(i+1)+1;
                while(s[adj]==s[nxt]){
                    nxt++;
                }
                if(nxt>=n){
                    break;
                }
                swap(s[adj],s[nxt]);
                i=adj+1;
            }
            else{
                i++;
            }
        }
        
        i=n-1;
        while(i>0){
        if(s[i]==s[i-1]){
            int nw_adj=i-1;
        int nw_nxt=(i-1)-1;
        while(nw_nxt>=0 && s[nw_adj]==s[nw_nxt]){
            nw_nxt--;
        }
        if(nw_nxt<0){
            return "";
        }
        swap(s[nw_adj],s[nw_nxt]);
          i=nw_adj-1;
        }
        else{
            i--;
        }
        }
        return s;
    }
};

 /* T.C = O(n*n) S.C=O(1) */