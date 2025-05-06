class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& list) {
        vector<vector<int>> adj(n);
        vector<int> in(n, 0);
        // itn m = list.size();
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
        int allcource = 0;
        while (!q.empty()) {
            int it = q.front();
            q.pop();
            cout << it << " ";
            res.push_back(it);
            allcource++;
            for (int j : adj[it]) {
                in[j]--;
                if (in[j] == 0) {
                    q.push(j);
                }
            }
        }

       return (allcource == n) ? res : vector<int>();
    }
};
