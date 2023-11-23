class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
       int n=word.size();
  
       set<string>st;
        for(auto it:forbidden){
            
            st.insert(it);
        }
        string ans;
        int fans=0;
        for(int i=0;i<n;i++){
            ans+=word[i];
            int m=ans.size();
            bool is=true;
            int idx=-1;
            for(int j=max(0,m-10);j<m;j++){
                string curr=ans.substr(j);
              
                if(st.count(curr)){
                  idx=j+1;
                }
            }
            if(idx!=-1){
                ans=ans.substr(idx);
            }
            fans=max(fans,(int)ans.size());
        }
        return fans;
    }
};