class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            int cnt = 0, lef = 0, rig = 0;
            // if odd
            lef = i, rig = i;
            while (lef >= 0 && rig < n && s[lef] == s[rig]) {
                lef--;
                rig++;
                cnt++;
            }
            res = res + cnt;
        // if evn
            lef = i, rig = i + 1;
            cnt = 0;
            while (lef >= 0 && rig < n && s[lef] == s[rig]) {
                lef--;
                rig++;
                cnt++;
            }
            res = res + cnt;
        }
        return res;
    }
};