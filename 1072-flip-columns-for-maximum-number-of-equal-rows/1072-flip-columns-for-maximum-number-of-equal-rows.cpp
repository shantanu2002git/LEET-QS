class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& maxt) {
        int n = maxt.size(), m = maxt[0].size();
        map<string, int> mps;

        for (auto rw : maxt) {
            string pattn;
            if (rw[0] == 0) {
                for (auto i : rw) {
                    pattn = pattn + to_string(i);
                }

                /*on this we consider the '0' is accepted one at mtx[0][0]*/
            } else {
                for (auto j : rw) {
                    pattn = pattn + to_string(j^1);
                    /*if the mtx[0][0]==1 then flip the bits of this row*/
                }
            }
            mps[pattn]++;
        }
        int res = -1;
        for (auto ti : mps) {
            res = max(ti.second, res);
        }
        return res;
    }
};