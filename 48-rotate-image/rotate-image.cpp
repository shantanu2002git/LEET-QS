class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        for (int l = 0; l < n; l++) {
            reverse(mat[l].begin(), mat[l].end());
        }
    }
};