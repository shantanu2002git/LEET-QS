#include <vector>

class Solution {
public:
    bool check(int i, int j, vector<vector<int>>&vec) {
       if(vec[i][j]==0 || vec[i][j]==1) return false;
        return true;
    }

    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> frame(n, vector<int>(m, -1)); // Initialize the vector with size and default value

        for (auto it : guards) {
            frame[it[0]][it[1]] = 1;
        }

        for (auto it : walls) {
            frame[it[0]][it[1]] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (frame[i][j] == 1) {
                    // up_going;
                    for (int p = i - 1; p >= 0; p--) {
                        if (!check(p, j,frame) ) {
                            break;
                        }
                        frame[p][j] = 99;
                    }

                    // dw_going;
                    for (int p = i + 1; p < n; p++) {
                        if (!check(p, j,frame) ) {
                            break;
                        }
                        frame[p][j] = 99;
                    }

                    // right_going;
                    for (int p = j + 1; p < m; p++) {
                        if (!check(i, p,frame) ) {
                            break;
                        }
                        frame[i][p] = 99;
                    }

                    // left_going;
                    for (int p = j - 1; p >= 0; p--) {
                        if (!check(i, p,frame) ) {
                            break;
                        }
                        frame[i][p] = 99;
                    }
                }
            }
        }

        int s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                s = s + (frame[i][j] == -1);
            }
        }
        return s;
    }
};
