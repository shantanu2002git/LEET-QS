class Solution
{
public:
    // 226
    int calldp(string s, int idx, int n, vector<int> &dp)
    {
        if (idx >= n)
        {
            return 1;
        }
        if(dp[idx]!=-1){
return dp[idx];
        }
        int step = 0;
        if (s[idx] != '0')
        {
            step = step + calldp(s, idx + 1, n, dp);
        }

        if (idx + 1 < n && (s[idx] == '1' || s[idx] == '2' && s[idx + 1] <= '6') )
        {
            step = step + calldp(s, idx + 2, n, dp);
        }
        return dp[idx]=step;
    }
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return calldp(s, 0, n, dp);
    }
};