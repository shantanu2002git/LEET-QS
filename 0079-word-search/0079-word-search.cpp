

class Solution {
public:
    int n, m;

    bool call(int i, int j, vector<vector<char>>& board,
              vector<vector<int>>& vis, int r, int t, string& s) {
        if (r == t) {
            return true; // Word found
        }
        
        if (i < 0 || j < 0 || i >= n || j >= m || s[r] != board[i][j] ||
            vis[i][j] == 1) {
            return false;
        }
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};


        vis[i][j] = 1;

        for (int l = 0; l < 4; l++) {
            int nx = dx[l] + i, ny = dy[l] + j;
            if (call(nx, ny, board, vis, r + 1, t, s)) {
               // vis[i][j] = 0; // Unmark visited for backtracking
                return true;
            }
        }
        vis[i][j] = 0; // Unmark visited for backtracking
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
        int t = word.size();
        bool res = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<int>> vis(n, vector<int>(m, 0));
                if (call(i, j, board, vis, 0, t, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};
