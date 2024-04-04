class Solution {
public:
    string repeatLimitedString(string s, int k) {
        int n = s.size(), i;
        priority_queue<pair<char, int>> q;
        vector<int> a(26);
        for (auto x : s) {
            a[x - 'a']++;
        }
        for (i = 0; i < 26; i++) {
            if (a[i] > 0) {
                q.push({i + 'a', a[i]});
            }
        }
        string ans = "";
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            int first_frq = f.second;
            char first_char = f.first;
            if (first_frq > k) {
                for (i = 0; i < k; i++) {
                    ans.push_back(first_char);
                }
                first_frq -= k;
                if (!q.empty()) {
                    auto sec = q.top();
                    char secn_char = sec.first;
                    int secn_frq = sec.second;
                    q.pop();
                    secn_frq--;
                    ans.push_back(secn_char);
                    if (secn_frq > 0) {
                        q.push({secn_char, secn_frq});
                    }
                } else {
                    break;
                }
                q.push({first_char, first_frq});
            } else {
                for (i = 0; i < first_frq; i++) {
                    ans.push_back(first_char);
                }
            }
        }
        return ans;
    }
};