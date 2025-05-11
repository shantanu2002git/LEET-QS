class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        // Min-heap: {max elevation so far, {x, y}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<>> pq;

        // Visited matrix
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        // Start from (0, 0) with elevation grid[0][0]
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        // 4 directions: up, down, left, right
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            // If we've reached bottom-right, return time
            if (x == n - 1 && y == n - 1) return time;

            // Explore neighbors
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    // Time becomes the max of current path and elevation at new cell
                    pq.push({max(time, grid[nx][ny]), {nx, ny}});
                }
            } 
        }

        return -1; // Should never reach here
    }
};
