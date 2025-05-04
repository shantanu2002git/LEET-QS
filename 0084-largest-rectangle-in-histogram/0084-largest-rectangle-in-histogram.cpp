class Solution {
public:
    int largestRectangleArea(vector<int>& hei) {
        int n = hei.size();
        vector<int> left(n, -1), right(n, n); // Next Smaller Left & Right
        stack<int> lf, rg;

        // Right -> NSR
        for (int i = n - 1; i >= 0; i--) {
            while (!rg.empty() && hei[rg.top()] >= hei[i]) {
                rg.pop();
            }
            if (!rg.empty()) {
                right[i] = rg.top();
            }
            rg.push(i);
        }

        // Left -> NSL
        for (int i = 0; i < n; i++) {
            while (!lf.empty() && hei[lf.top()] >= hei[i]) {
                lf.pop();
            }
            if (!lf.empty()) {
                left[i] = lf.top();
            }
            lf.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, hei[i] * (right[i] - left[i] - 1));
        }

        return res;
    }
};
