class Solution {
public:
const int mod = 1e9 + 7;
map<pair<int, int>, int> dp;

int cal(int steps, int idx, int n){
     if (steps == 0)
    {
      return idx == 0;
    }
    else if (idx >= n || idx < 0)
    {
      return 0;
    }

    if (dp.find({steps, idx}) != dp.end())
    {
      return dp[{steps, idx}];
    }
    int lef_ttk = cal(steps - 1, idx - 1, n);
    int rig_ttk = cal(steps - 1, idx + 1, n);
    int sty_ttk = cal(steps - 1, idx, n);
    return dp[{steps, idx}] = ((lef_ttk + rig_ttk) % mod + sty_ttk) % mod;
}
    int numWays(int steps, int arrLen) {
        return  cal(steps,0,arrLen); 
    }
};