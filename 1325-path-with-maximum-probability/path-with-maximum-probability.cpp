class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succp, int start_node, int end_node) {
        vector<double>vis_pp(n,0.0);
        vector<vector<pair<int,double>>>adj(n);
      int i=0;
        for(auto it : edges){
            int ui=it[0],vi=it[1];
            adj[ui].push_back({vi,succp[i]});
            adj[vi].push_back({ui,succp[i]});
            i++;
        }
     queue<int>q;
        q.push(start_node);
    vis_pp[start_node]=1.0;

        while(!q.empty()){
            auto nod=q.front();
            q.pop();
for(auto it : adj[nod]){
    auto nxnd=it.first;
    double  prp=it.second;
    double nw=prp*vis_pp[nod];

    if(nw>vis_pp[nxnd]){
        vis_pp[nxnd]=nw;
        q.push(nxnd);
    }
}
        }

        return vis_pp[end_node];


    }
};