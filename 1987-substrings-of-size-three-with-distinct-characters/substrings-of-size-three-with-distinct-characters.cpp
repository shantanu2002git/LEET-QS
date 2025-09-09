class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int i = 0, j = 0, res=0;
        map<char, int> mp;
        while (i < n) {
            mp[s[i]]++;
           
            while (i - j + 1 > 3) {
                mp[s[j]]--;
                if (mp[s[j]] == 0) {
                    mp.erase(s[j]);
                }
                j++;
            }
             if (mp.size() == 3 && i - j + 1 == 3) {
                res++;
            }
            i++;
        }
        return res;
    }
};