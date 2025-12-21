class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1,
                                          vector<vector<int>>& items2) {
        vector<int> adj(1005, 0);
        int mxv = 0;
        for (auto &it : items1) {
            adj[it[0]] = adj[it[0]] + it[1];
            mxv = max(it[0], mxv);
        }
        for (auto &it : items2) {
            adj[it[0]] = adj[it[0]] + it[1];
            mxv = max(it[0], mxv);
        }
        vector<vector<int>>res;
        for (int i = 0; i <= mxv; i++) {
            cout<<adj[i]<< " ";
            if(adj[i]!=0){

            res.push_back({i,adj[i]});
            }
        }
        return res;
    }
};