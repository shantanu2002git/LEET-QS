class Solution {
public:
    vector<string> res;
    void call(string si, int opn, int cls, int n) {
        if (opn == n && cls == n) {
            res.push_back(si);
            return;
        }

        if (opn < n) {
            call(si + '(', opn + 1, cls, n);
        }
        if (cls < opn) {
            call(si + ')', opn, cls + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        call("", 0, 0,n );
        return res;
    }
};