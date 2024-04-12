class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> prf(n), suf(n);
        prf[0]=h[0];
        for (int i = 1; i < n; i++) {
            prf[i] = max(prf[i - 1], h[i]);
        }
         suf[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], h[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = res + min(prf[i], suf[i]) - h[i];
        }
        return res;
    }
};