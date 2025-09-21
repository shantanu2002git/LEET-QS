class Solution {
public:
    map<string, int> mps;
    vector<int> dp;
    bool calldp(int st, string s, int n) {
        if (st == n) {
            return true;
        }
        if (dp[st] != -1) {
            return dp[st];
        }
        for (int i = st; i < n; ++i) {
            string subs = s.substr(st, i - st + 1);
            if (mps.find(subs) != mps.end()) {
                if (calldp(i + 1, s, n))  // keep this condition if the substring is matched then start next to [i+1]....
                    return dp[st] = true;
            }
        }
        return dp[st] = false;
    }
    bool wordBreak(string s, vector<string>& wd) {

        for (auto it : wd) {
            mps[it]++;
        }
        int n = s.size();
        dp.assign(n, -1);
        return calldp(0, s, n);
    }
};