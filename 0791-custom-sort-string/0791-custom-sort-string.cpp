class Solution {
public:
    string customSortString(string order, string s) {
        string res;

        map<char, int> smp;
        for (int i = 0; i < s.size(); i++) {
            smp[s[i]]++;
        }
        for (char i : order) {
            if (s.find(i) != string::npos) {
                char c = i;
                int cnt = smp[i];
                while (cnt--) {
                    res = res + c;
                }
                // res += i;
            }
        }

        for (char j : s) {
            if (res.find(j) == string::npos) {
                char c = j;
                int cnt = smp[j];
                while (cnt--) {
                    res = res + c;
                }
                // res += j;
            }
        }

        return res;
    }
};
