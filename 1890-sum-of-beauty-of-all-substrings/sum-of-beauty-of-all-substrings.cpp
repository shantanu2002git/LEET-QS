#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    void _max_min(int& mx, int& mi, vector<int>& fq) {
        mi = INT_MAX;
        mx = INT_MIN;
        for (int i = 0; i < 26; i++) {
            if (fq[i] != 0) {
                mi = min(mi, fq[i]);
                mx = max(mx, fq[i]);
            }
        }
    }

public:
    int beautySum(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; i++) {
            vector<int> Al(26, 0);
            for (int j = i; j < n; j++) {
                Al[s[j] - 'a']++;
                int mx, mi;
                _max_min(mx, mi, Al);
                res += mx - mi;
            }
        }
        return res; //n*n*26
    }
};
