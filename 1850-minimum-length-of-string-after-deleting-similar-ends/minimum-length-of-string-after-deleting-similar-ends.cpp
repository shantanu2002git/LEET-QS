class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0, r = n-1;
        while(l<r){
            if(s[l] != s[r]){
                break;
            }
            while(s[l] == s[r] and l <r){
                r--;
            }
            r++;
            while(s[l] == s[r] and l<r){
                l++;
            }
            r--;
        }
        return max(0,r- l +1);
    }
};