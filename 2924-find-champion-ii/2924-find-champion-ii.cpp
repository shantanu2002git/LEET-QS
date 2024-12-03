
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> inDegree(n, 0);

        // Build adjacency list and in-degree array
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
        }

        queue<int> q;
        int candidate = -1;

        // Push nodes with in-degree 0 into the queue
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                if (candidate != -1) { // More than one source
                    return -1;
                }
                candidate = i;
                q.push(i);
            }
        }

        // Perform BFS/Topological Sort
        int processed = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;

            for (auto neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If all nodes are processed and there’s a unique candidate
        return (q.size()==0) ? candidate : -1;
    }
};
