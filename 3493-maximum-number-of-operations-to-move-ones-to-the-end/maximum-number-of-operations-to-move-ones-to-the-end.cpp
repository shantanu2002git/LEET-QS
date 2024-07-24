class Solution {
public:
    int maxOperations(string s) {
        int cnt = 0, res = 0,n=s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                cnt++;
            else {
                while (i < n && s[i] != '1') {
                    i++;
                }
                res += cnt;
                cnt++; // since s[i] = 1 after the while loop if (i < n)
            }
        }
        return res;
    }
};