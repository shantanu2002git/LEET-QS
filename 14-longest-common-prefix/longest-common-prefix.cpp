class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());
        int k=strs.size();
         string fst=strs[0],lst=strs[k-1], ans="";
         int n=fst.size(),m=lst.size();
      
         for(int i=0; i<min(n,m); i++){
             if(fst[i]!=lst[i]){
                 return ans;
             }
             ans=ans+fst[i];
         }
         return ans;

    }
};