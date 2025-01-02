class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int totone = 0, remone = 0;

        for (int i = 0; i < n; i++) {
            totone += (s[i] == '1');
        }
        int rs = INT_MIN;
        int zerox = 0;
        for (int i = 0; i < n; i++) {
            zerox += (s[i] == '0');
            remone += (s[i] == '1');

            rs = max(rs, zerox + (totone - remone));
        }
        return rs;
    }
};