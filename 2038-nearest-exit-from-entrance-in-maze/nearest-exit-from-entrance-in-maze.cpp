// class Solution
// {//https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1
// public:
//     int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

//     }
// };

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, int>> q;
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, 1, -1, 0};

        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int dist = 0;
        while (!q.empty()) {

            int s = q.size();

            while (s) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int row = x + dx[i];
                    int col = y + dy[i];
                    if (row >= 0 && col >= 0 && row < n && col < m &&
                        maze[row][col] == '.') {
                        if (row == 0 || col == 0 || row == n - 1 ||
                            col == m - 1)
                            return dist + 1;
                        maze[row][col] = '+';
                        q.push({row, col});
                    }
                }
                s--;
            }
            dist++;
        }
        return -1;
    }
};