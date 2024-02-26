class Solution {
public:
    string maxValue(string ns, int x) {
        int n = ns.size(), j = 0;
        string res;

        if (ns[0] == '-') {
            j = 1;
            while (j < n) {
                int di = ns[j] - '0';
                if (di > x) {
                    break;
                }
                j++;
            }

            res = ns.substr(0, j) + to_string(x) + ns.substr(j,n);

        } else {
            j = 0;
            while (j < n) {
                int di = ns[j] - '0';
                if (di < x) {
                    break;
                }
                j++;
            }

            res = ns.substr(0, j) + to_string(x)+ ns.substr(j,n);
        }

        return res;
    }
};