class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.size();
        bool res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' && s[i - 1] != s[i + 1]) {
                cout << s[i] << " ji";
               
                return false;
            }if(s[i]==' '){
                 res = 1;
            }
        }
      if(res==0){
        return s[0]==s[s.size()-1];
      }else{
        return s[0]==s[s.size()-1];
      }
    }
};