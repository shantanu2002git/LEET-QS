class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if ('0' <= s[i] && s[i] <= '9') {
                s[i] = '*';
                for (int j = max(0, i - 1); j >= 0; j--) {
                    if ('a' <= s[j] && s[j] <= 'z') {
                        s[j] = '*';
                        break;
                    }
                }
            }
        }
        string res="";
        for(int i=0; i<n; i++){
            if(s[i]!='*'){
                res=res+s[i];
            }
        }
        return res;
    }
};