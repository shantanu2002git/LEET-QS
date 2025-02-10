class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), c = 0;
        map<char,int>ms1,ms2;
        for (int i = 0; i < n; i++) {
            ms1[s1[i]]++;
            ms2[s2[i]]++;
            if (s1[i] != s2[i]) {
                c++;
            }
        }
        /*
        caa
        aaz
         sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        */
       
        for(int i=0; i<n; i++){
            if(ms1[s1[i]]!=ms2[s1[i]]){
                return 0;
            }
        }
        return (c == 2 || c==0);
    }
};