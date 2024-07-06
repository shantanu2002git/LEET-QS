class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> adj[n + 1];
        vector<int> in(n + 1, 0); // Initialize the in-degree vector with 0

        for (auto it : roads) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            in[u]++;
            in[v]++;
        }

        vector<int> city(n);
        for (int i = 0; i < n; i++) {
            city[i] = i;
        }

        sort(city.begin(), city.end(), [&](int it1, int it2) {
            return in[it1] > in[it2]; // Corrected the comparator
        });

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long long)(n - i) * in[city[i]];
        }

        return res;
    }
};
