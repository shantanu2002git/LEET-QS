class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n - 1, res = 0;
        while (l < r) {
            int wd = (r - l );
            res = max(res, min(h[l], h[r]) * wd);
            cout << wd << " ";
            if (h[l] <= h[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};