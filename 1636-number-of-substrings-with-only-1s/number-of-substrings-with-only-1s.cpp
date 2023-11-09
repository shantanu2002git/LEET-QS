class Solution {
public:
    int numSub(string s) {
        int n=s.size(), cnt1=0, res=0,mod=1e9+7;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                cnt1++;
                res=(cnt1+res)%mod;
            }else{
                cnt1=0;
            }
        }
        return res;
    }
};