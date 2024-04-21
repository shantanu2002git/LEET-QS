class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);

        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> seen(n);
        queue<int> q;
        q.push(source);
        seen[source] = 1;

        while (!q.empty()) {
            int fnt = q.front();
            q.pop();
            if (fnt == destination) {
                return 1;
            }

            for (auto it : adj[fnt]) {
                if (!seen[it]) {
                    seen[it] = 1;
                    q.push(it);
                }
            }
        }
        return false;
    }
};