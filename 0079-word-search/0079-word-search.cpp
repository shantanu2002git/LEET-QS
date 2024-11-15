class Solution {
public:
    bool isHave(int i, int j, int l, vector<vector<char>>& board, string& word,
                vector<vector<int>>& vis) {
        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1 ||
            board[i][j] != word[l]) {
            return false;
        }
        if (l == word.size() - 1) {
            return true;
        }
        vis[i][j] = 1;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int c = 0; c < 4; c++) {
            int nx = i + dx[c], ny = j + dy[c];
            if (isHave(nx, ny, l + 1, board, word, vis)) {
                return true;
            }
        }

        // Backtrack: unmark the current cell
        vis[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Start DFS from every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] &&
                    isHave(i, j, 0, board, word, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
