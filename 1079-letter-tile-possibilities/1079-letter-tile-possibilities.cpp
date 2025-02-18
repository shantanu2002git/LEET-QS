class Solution {
public:
    set<string> unq;
    void call(string tiles, string si, int idx, int n, vector<bool>&visit) {
        // if(idx>=n) return;

        unq.insert(si);
        for (int idx = 0; idx < n; idx++) {
            if (visit[idx] == 0) {
                si = si + tiles[idx];
                visit[idx] = true;
                call(tiles, si, 0, n, visit);
                si.pop_back();
                visit[idx] = false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        string si = "";
        int n = tiles.size();
        vector<bool> visit(n, 0);

        call(tiles, si, 0, n, visit);
        return unq.size()-1;
    }
};