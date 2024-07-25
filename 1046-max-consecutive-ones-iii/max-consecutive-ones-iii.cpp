class Solution {
public:
    int longestOnes(vector<int>& zrr, int k) {
        int on = 0, zr = 0, mx = 0;
        int i = 0, j = 0, n = zrr.size();
        while (i < n) {
            if (zrr[i] == 0) {
                zr++;
            }
            while (zr > k) {
                if (zrr[j] == 0) {
                    zr--;
                }
                j++;
            }
            mx = max(mx, (i - j + 1));
            cout << 'x';
            i++;
        }

        return mx;
    }
};