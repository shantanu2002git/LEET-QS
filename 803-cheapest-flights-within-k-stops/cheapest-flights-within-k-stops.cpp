class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fli, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n );
        for (auto it : fli) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> cost(n + 1, 1e9);
        q.push({0, {src, 0}}); // cntp, src, cost;
            cost[src] = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int cp = it.first, from = it.second.first, cos = it.second.second;
            if(cp>k){
                continue;
            }
            for (auto it : adj[from]) {
                int to = it.first, prc = it.second;
                if (cos + prc < cost[to]) {
                    cost[to] = cos + prc;
                    q.push({cp + 1, {to, (cos + prc)}});
                }
            }
        }
        if (cost[dst] == 1e9) {
            return -1;
        }
        return cost[dst];
    }
};