class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        // Distance matrix initialized to infinity
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        
        // Store portal coordinates for each letter
        vector<vector<pair<int,int>>> portals(26);
        vector<bool> used(26, false); // Portal usage tracker

        // Preprocess portal positions
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                char ch = matrix[i][j];
                if (ch >= 'A' && ch <= 'Z')
                    portals[ch - 'A'].push_back({i, j});
            }

        // Directions: right, left, down, up
        vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        
        // Start from (0, 0)
        dist[0][0] = 0;

        // Min-heap based on distance
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({0, 0, 0}); 
        
        while (!pq.empty()) {
            auto [d, x, y] = pq.top(); pq.pop();

            // Skip if already processed with smaller distance
            if (dist[x][y] < d) continue; 
            
            // Destination reached
            if (x == m - 1 && y == n - 1) 
                return d;
            
            // Handle teleportation
            char c = matrix[x][y];
            if (c >= 'A' && c <= 'Z') {
                int id = c - 'A';
                if (!used[id]) {
                    used[id] = true;
                    for (auto& [px, py] : portals[id]) {
                        if (px == x && py == y) continue;
                        if (dist[px][py] > d) {
                            dist[px][py] = d;
                            pq.push({d, px, py});
                        }
                    }
                }
            }

            // Explore 4 directions
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && matrix[nx][ny] != '#') {
                    int nd = d + 1;
                    if (dist[nx][ny] > nd) {
                        dist[nx][ny] = nd;
                        pq.push({nd, nx, ny});
                    }
                }
            }
        }

        // Destination not reachable
        return -1;
    }
};