class Solution {
public:
    vector<string> printVertically(string s) {
    vector<string> ans;
    s = s + ' ';
    string tem;
    int mx = -1, c = 0;

    for (auto it : s) {
        c++;
        if (it == ' ') {
            ans.push_back(tem);
            mx = max(mx, c);
            c = 0;
            tem.clear();
        } else {
            tem = tem + it;
        }
    }

    vector<string> res;
    int n = ans.size();  // Fix: Use the size of ans, not s
    for (int j = 0; j < mx; j++) {
        string nwtem;
        for (int i = 0; i < n; i++) {
            if (j < ans[i].size()) {
                nwtem = nwtem + ans[i][j];
            } else {
                nwtem += ' ';
            }
        }
        // Move this outside of the inner loop
        while (!nwtem.empty() && nwtem.back() == ' ') {
            nwtem.pop_back();
        }
        res.push_back(nwtem);
    }
res.pop_back();
    return res;

    }
};