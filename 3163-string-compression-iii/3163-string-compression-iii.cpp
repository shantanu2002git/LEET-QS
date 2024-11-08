class Solution {
public:
    string compressedString(string w) {
        int n = w.size(), i = 0, c = 0;
        string res = "";
        while (i < n) {
            char ci = w[i];
            i = i + 1;
            c = c + 1;
            while (ci == w[i] && i < n && c <9) {
                i++;
                c++;
            }
            res.append(to_string(c));
            res.push_back(ci);
            c = 0;
        }
        return res;
    }
};