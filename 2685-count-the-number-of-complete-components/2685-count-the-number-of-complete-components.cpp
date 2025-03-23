class Solution {
public:
    bool allgo(int nd, int n, vector<vector<int>>& adj, vector<int>& visit) {
        queue<int> q;
        q.push(nd);
        visit[nd] = 1;

        vector<int> nodes;
        int edgeCount = 0;

        while (!q.empty()) {
            int tp = q.front();
            q.pop();
            nodes.push_back(tp);

            for (auto it : adj[tp]) {
                edgeCount++; // Counting edges
                if (!visit[it]) {
                    visit[it] = 1;
                    q.push(it);
                }
            }
        }

        int totalNodes = nodes.size();
        int expectedEdges = (totalNodes * (totalNodes - 1)) / 2;

        return edgeCount / 2 == expectedEdges; // Each edge is counted twice
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visit(n, 0);
        int res = 0;

        for (int nd = 0; nd < n; nd++) {
            if (!visit[nd] && allgo(nd, n, adj, visit)) {
                res++;
            }
        }
        return res;
    }
};
