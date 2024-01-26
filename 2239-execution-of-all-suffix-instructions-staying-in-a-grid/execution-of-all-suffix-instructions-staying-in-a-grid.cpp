class Solution {
public:
    bool valid(int x, int y, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int si = s.size();
        vector<int> res;
        int x = startPos[0], y = startPos[1];

        for (int i = 0; i < si; i++) {
            int cnt = 0;

            for (int j = i; j < si; j++) {
                if (s[j] == 'R') {
                    y = y + 1;
                } else if (s[j] == 'L') {
                    y = y - 1;
                } else if (s[j] == 'U') {
                    x = x - 1;
                } else if (s[j] == 'D') {
                    x = x + 1;
                }

                if (valid(x, y, n)) {
                    cnt++;
                } else {
                    break;
                }
            }

            // Reset the position 
            x = startPos[0], y = startPos[1];
            
            res.push_back(cnt);
        }

        return res;
    }
};
