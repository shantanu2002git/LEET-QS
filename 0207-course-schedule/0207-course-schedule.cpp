class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& list) {

        vector<int> adj[n];
        vector<int> in(n, 0);

        for (auto it : list) {

            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;
        while (!q.empty()) {
            int it = q.front();
            q.pop();
            cout<<it<<" ";
            res.push_back(it);
            for (int j : adj[it]) {
                // cout<<in[j]<<<" fs ";
                in[j]--;
                // // cout<<in[j]<<<" fs ";
                if (in[j] == 0) {
                    q.push(j);
                }

                // cout<<j[0]<<" ";
            }
        }

        return res.size()==n;
    }
};