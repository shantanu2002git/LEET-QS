class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mps,mpt;
        for(int i : s){
            mps[i]++;
        }
        for(int j : t){
            mpt[j]++;
        }
        int res=0;
        for(auto it : mps){
            if(mpt.find(it.first)==mpt.end()){
                res=res+it.second;
            }else{
                res=res+abs(mpt[it.first]-it.second);
            }
        }

        for(auto it : mpt){
            if(mps.find(it.first)==mps.end()){
                res=res+it.second;
            }
        }
        return res;
    }
};