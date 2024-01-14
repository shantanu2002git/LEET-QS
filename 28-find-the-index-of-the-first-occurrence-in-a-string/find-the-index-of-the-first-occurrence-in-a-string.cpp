class Solution {
public:
    int strStr(string h, string ne) {
        int n =h.size();
        int m=ne.size();
        for(int i=0; i<n; i++){
            string si=h.substr(i,m);
            if(si==ne){
                return i;
            }
        }
        return -1;
    }
};