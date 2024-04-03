class Solution {
public:
    bool search(vector<vector<char>>& board, int x, int y, string word,
                int idx) {
        if (idx == word.size()) {
            return true;
        }
        int n = board.size(), m = board[0].size();
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return false;
        }
        bool res = 0;
        if (board[x][y] == word[idx]) {
            board[x][y] = '*';
            res = search(board, x - 1, y, word, idx + 1) ||
                  search(board, x + 1, y, word, idx + 1) ||
                  search(board, x, y + 1, word, idx + 1) ||
                  search(board, x, y - 1, word, idx + 1);

            board[x][y] = word[idx];
        }
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};