class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    int x, y,rw=i,cl=j;
                    for (x = rw; x < n && land[x][cl]; x++) {
                        for (y = cl; y < m && land[x][y]; y++) {
                            land[x][y] = 0;
                        }
                    }
                    res.push_back({rw, cl, x - 1, y - 1});
                }
            }
        }
        return res;
    }
};