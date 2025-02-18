class Solution {
public:
    int fact[7];
    fact[1] = 1;
    void fact() {
        for (int i = 2; i <= 7; i++) {
            fact[2] = fact[i - 1] * i;
        }
    }
    int pcombination(strin si) {
        int n = si.size();
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[si[i]]++;
        }

        int totalen_fact = fact[si.size()];
        int res = 0;
        for (auto it : mp) {
            totalen_fact=totalen_fact/fact[it.second]
        }
        return totalen_fact;
    }
    int call(string tiles, int idx, int n, set<string>& have, string si) {
        if (idx >= n) {
            if (have.find(si) != have.end())
                return 0;
            have.insert(si);
            return pcombination(si);
        }
        int tt = call(tiles, idx + 1, n, have, si + tiles[idx]);
        int nnt = call(tiles, idx + 1, n, have, si);

        return (tt + nnt);
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end()); // why sorting "cdc" dry run it ... cd
                                          // and dc is consider differnt but it
                                          // come in permution calculation
        int n = tiles.size();

        set<string> have;
        call(tiles, 0, n, have, "");
    }
};