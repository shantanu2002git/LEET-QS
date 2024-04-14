class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        int n = s.size();
        int res = 0;
        sort(s.begin(), s.end());
        vector<int> vl(n);
        for (int i = 0; i < n; i++) {
            vl[i] = s[i] - '0';
        }
        int n1 = 0, n2 = 0;
        for (int i = 0; i < n; i = i + 2) {
            n1 = n1 * 10 + vl[i];
        }
        for (int i = 1; i < n; i = i + 2) {
            n2 = n2 * 10 + vl[i];
        }
        return n1+n2;
    }
};
