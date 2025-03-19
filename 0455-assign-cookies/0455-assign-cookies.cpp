class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       
        if(s.empty()){
            return 0;
        }
        sort(g.begin(),g.end());
        sort(s.begin(), s.end());
        int n=g.size(),m=s.size(),i=0,j=0,res=0;
        while(i<n && j<m){
            if(g[i]>s[j]){
                j++;
            }else{
                res++;
                s[j]=0;
                i++;
            }
        }
        return res;
    }
};