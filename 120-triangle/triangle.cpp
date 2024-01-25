class Solution {
public:
    int call(int x, int y, int n, vector<vector<int>>& tri, vector<vector<int>>& dp) {
        if (x == n) {
            return 0;
        }
if(dp[x][y]!=-1){
    return dp[x][y];
}
        int res;
        res =
            tri[x][y] + min(call(x + 1, y, n, tri,dp), call(x + 1, y + 1, n, tri,dp));
        return dp[x][y]=res;
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return call(0, 0, n, tri,dp);
    }
};