class Solution {
public:
    bool valid(char vl, int rw, int cl, vector<vector<char>>&bd) {
        for (int i = 0; i < 9; i++) {
            if (bd[rw][i] == vl || bd[i][cl] == vl)
                return false;
        }
        int srw =  (rw / 3)*3, scl =  (cl / 3)*3;
        for (int i = srw; i < srw + 3; i++) {
            for (int j = scl; j < scl + 3; j++) {
                if (bd[i][j]==vl)
                    return false;
            }
        }
        return true;
    }
    bool call(vector<vector<char>>& bd) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (bd[i][j] == '.') {
                    for (char vl = '1'; vl <= '9'; vl++) {
                        if (valid(vl, i, j, bd)) {
                           bd[i][j]=vl;
                           if(call(bd)) return true;
                           bd[i][j]='.'; 
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { call(board); }
};