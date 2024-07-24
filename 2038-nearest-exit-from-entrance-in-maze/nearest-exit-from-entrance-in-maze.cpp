#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        queue<pair<int, int>> q;
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, 1, -1, 0};
        int n = maze.size(), m = maze[0].size();
        q.push({ent[0], ent[1]});
        maze[ent[0]][ent[1]] = '+';
        int des = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto it = q.front();
                q.pop();
                int x = it.first, y = it.second;
                for (int l = 0; l < 4; l++) {
                    int nx = x + dx[l], ny = y + dy[l];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        maze[nx][ny] == '.') {
                        if (nx == 0 || ny == 0 || nx == n-1 || ny == m-1) {
                            return des + 1;
                        }
                        q.push({nx, ny});
                        maze[nx][ny] = '+';
                    }
                }
            }
            des++;
        }
        return -1;
    }
};
