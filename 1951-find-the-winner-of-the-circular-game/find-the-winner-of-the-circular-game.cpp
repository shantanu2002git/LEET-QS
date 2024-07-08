class Solution {
public:
    int findTheWinner(int n, int k) {
        int tp;
        queue<int>q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        if (k == 1) {
            return n;
        }
        while (!q.empty()) {
            int kx = k - 1;
            while (kx--) {
                tp = q.front();
                q.pop();
                q.push(tp);
            }
            q.pop();
        }
        return tp;
    }
};