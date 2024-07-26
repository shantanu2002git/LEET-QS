class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int cnt = 0;
        map<char, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
            if (mpp[s[i]] > 2) {
                cnt = cnt + 2;
                mpp[s[i]] = mpp[s[i]] - 2;
            }
        }
        int ans = n - cnt;
        return ans;
    }
};