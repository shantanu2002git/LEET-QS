class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        // Adjacency list: node -> {neighbor, cost}
        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w}); // reverse edge has double cost
        }

        // Min-heap: {cost, node}
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> dist(n, INT_MAX);

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            // Optimization: skip outdated entries
            if (cost > dist[node]) continue;

            for (auto &[next, weight] : adj[node]) {
                if (dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};
