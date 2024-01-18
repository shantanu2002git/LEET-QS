class Solution {
public:
    bool rotateString(string s, string g) {
        int n=s.size(),m=g.size();
        if(n!=m){
            return 0;
        }
         g = g + g;

        if (g.find(s) != string::npos) {
            return true;
        }

        return false;
    }
};