class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> mps;
        for (int i : s) {
            mps[i]++;
        }
        int res = 0;
        for (int j : t) {

            if (mps.find(j) != mps.end()) {
                mps[j]--;
                if (mps[j] == 0) {
                    mps.erase(j);
                }
            } else {
                res++;
            }
        }

        for (auto it : mps) {
            res = res + it.second;
        }

        return res;
    }
};