class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                int mx = -1e9, mn = 1e9;
                for (auto& kv : mp) {
                    mx = max(mx, kv.second);
                    mn = min(mn, kv.second);
                }
                res += mx - mn;
            }
        }
        return res;
    }
};
