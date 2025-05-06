class Solution {
public:
    void solve(vector<vector<char>>& bd) {
        queue<pair<int, int>> q, temq; // store boundery 'O'
        int n = bd.size(), m = bd[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
     for (int i = 0; i < n; i++) {
    if (bd[i][0] == 'O' && vis[i][0] == 0) {
        q.push({i, 0});
        vis[i][0] = 1;
    }
    if (bd[i][m - 1] == 'O' && vis[i][m - 1] == 0) {
        q.push({i, m - 1});
        vis[i][m - 1] = 1;
    }
}
for (int j = 0; j < m; j++) {
    if (bd[0][j] == 'O' && vis[0][j] == 0) {
        q.push({0, j});
        vis[0][j] = 1;
    }
    if (bd[n - 1][j] == 'O' && vis[n - 1][j] == 0) {
        q.push({n - 1, j});
        vis[n - 1][j] = 1;
    }
}

        temq = q;
        while (!temq.empty()) {
            auto it = temq.front();
            temq.pop();
            cout << bd[it.first][it.second] << " : q" << endl;
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while (!q.empty()) {
            int nq = q.size();
            while (nq--) {
                auto it = q.front();
                q.pop();
                int x = it.first, y = it.second;
                // vis[x][y] = 1;
                for (int i = 0; i < 4; i++) {
                    int nwx = dx[i] + x, nwy = dy[i] + y;
                    if (nwx >= 0 && nwx < n && nwy >= 0 && nwy < m &&
                        bd[nwx][nwy] == 'O' && vis[nwx][nwy] == 0) {
                        q.push({nwx, nwy});
                        vis[nwx][nwy] = 1;
                    }
                }
            }
        }

        for (auto it : vis) {
            for (auto i : it) {
                cout << i << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0) {
                    cout << i << j;
                    bd[i][j] = 'X';
                    cout << bd[i][j] << " ";
                }
            }
        }
        // return bd;
    }
};