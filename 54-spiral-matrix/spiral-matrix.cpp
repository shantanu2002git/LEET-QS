class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> res;
        spiralOrderRecursive(mat, 0, mat.size() - 1, 0, mat[0].size() - 1, 1, res);
        return res;
    }
    
    void spiralOrderRecursive(vector<vector<int>>& mat, int top, int bot, int lef, int rig, int direc, vector<int>& res) {
        if (lef > rig || top > bot)
            return;
        
        if (direc == 1) {
            for (int i = lef; i <= rig; i++) {
                res.push_back(mat[top][i]);
            }
            spiralOrderRecursive(mat, top + 1, bot, lef, rig, 2, res);
        } else if (direc == 2) {
            for (int i = top; i <= bot; i++) {
                res.push_back(mat[i][rig]);
            }
            spiralOrderRecursive(mat, top, bot, lef, rig - 1, 3, res);
        } else if (direc == 3) {
            for (int i = rig; i >= lef; i--) {
                res.push_back(mat[bot][i]);
            }
            spiralOrderRecursive(mat, top, bot - 1, lef, rig, 4, res);
        } else if (direc == 4) {
            for (int i = bot; i >= top; i--) {
                res.push_back(mat[i][lef]);
            }
            spiralOrderRecursive(mat, top, bot, lef + 1, rig, 1, res);
        }
    }
};
