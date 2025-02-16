class Solution {
public:
    int len;
    vector<int> res;
    vector<bool> visit;
    bool call(int len, int idx) {

        if (idx == len)
            return true;

        if (visit[idx] != 0)
           return call(len, idx + 1);

        for (int num = len; num >= 1; num--) {
            int nxtIdx = (num > 1) ? num + idx : idx;
            if (nxtIdx >= len || res[nxtIdx] != 0 || visit[num] != 0)
                continue;

            visit[num] = 1;
            res[idx] = res[nxtIdx] = num;

            if (call(len, idx + 1))
                return true;
            visit[num] = 0;
            res[num] = res[nxtIdx] = 0;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        len = 2 * n - 1;
        res.assign(len, 0);
        visit.assign(n+1,0);
        call(len, 0);
        return res;
    }
};