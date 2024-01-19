class Solution {
public:
    int n, m;

    void cal(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '#' || board[x][y] == 'X') {
            return;
        }
        board[x][y] = '#';
        cal(board, x + 1, y);
        cal(board, x - 1, y);
        cal(board, x, y + 1);
        cal(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        // Traverse the border and connected cells, mark them with '#'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O') {
                    cal(board, i, j);
                }
            }
        }

        // Update the board based on marked cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
