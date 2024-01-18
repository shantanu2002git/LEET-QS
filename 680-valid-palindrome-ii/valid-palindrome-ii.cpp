class Solution {
public:
bool call(string s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;j--;
    }
    return true;
}
    bool validPalindrome(string s) {
        int n=s.size()-1,i=0;
        while(i<n){
            if(s[i]==s[n]){
                i++;n--;
            }else{
                return call(s,i+1,n) || call(s,i,n-1);
            }
        }
        return true;
    }
};