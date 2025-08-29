class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m)
            return 0;
        vector<int> vl(26, 0);
        for (int i = 0; i < n; i++) {
            vl[s[i]-'a']++;
        }
        for (int i = 0; i < m; i++) {
            vl[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(vl[i]!=0){
                return 0;
            }
        }
        return 1;
    }

}
;