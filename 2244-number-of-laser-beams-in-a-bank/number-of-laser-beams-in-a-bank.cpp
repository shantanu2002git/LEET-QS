class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> ls;
        for (auto it : bank) {
            int l = 0;
            for (auto i : it) {
                if (i == '1') {
                    l++;
                }
            }
            if (l > 0) {
                ls.push_back(l);
            }
        }
        for (auto it : ls) {
            cout << it << " ";
        }
        int res = 0;
        for (int i = 1; i < ls.size(); i++) {
            res = res + (ls[i - 1] * ls[i]);
        }
        return res;
    }
};