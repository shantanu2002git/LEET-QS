

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<pair<int, int>> cityReachCount; // (city, reachableCount)

        // Function to perform BFS and count reachable cities within distanceThreshold
        auto bfs = [&](int startCity) -> int {
            vector<int> dist(n, INT_MAX);
            queue<int> q;
            q.push(startCity);
            dist[startCity] = 0;
            int reachableCount = 0;

            while (!q.empty()) {
                int city = q.front();
                q.pop();

                for (const auto& neighbor : adj[city]) {
                    int nextCity = neighbor.first;
                    int weight = neighbor.second;

                    if (dist[city] + weight < dist[nextCity]) {
                        dist[nextCity] = dist[city] + weight;
                        q.push(nextCity);
                    }
                }
            }

            // Count reachable cities within distanceThreshold
            for (int i = 0; i < n; ++i) {
                if (dist[i] <= distanceThreshold && dist[i] != INT_MAX) {
                    reachableCount++;
                }
            }

            return reachableCount;
        };

        // Perform BFS from each city to determine reachable cities within the threshold
        for (int i = 0; i < n; ++i) {
            int reachableCount = bfs(i);
            cityReachCount.push_back({i, reachableCount});
        }

        // Sort cities first by number of reachable cities (ascending), then by city index (descending)
        sort(cityReachCount.begin(), cityReachCount.end(), [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.second == p2.second ? p1.first > p2.first : p1.second < p2.second;
        });

        return cityReachCount[0].first; // Return the city with the smallest number of reachable cities
    }
};
