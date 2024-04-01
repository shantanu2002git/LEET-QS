class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(), res=0,l=n-1;
       while(l>=0 && s[l]==' '){
        l--;
       }
       while(l>=0 && s[l]!=' '){
        l--;
        res++;
       }
        return res;
    }
};