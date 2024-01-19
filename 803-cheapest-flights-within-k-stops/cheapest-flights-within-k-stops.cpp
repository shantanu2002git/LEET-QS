class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>cost(n,INT_MAX);
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;
        cost[src]=0;
        q.push({0,{src,0}});
       
       while(!q.empty()){
           auto it =q.front();
           q.pop();
           int stp=it.first, nod=it.second.first, pric=it.second.second;
           if(stp>k){
               continue;
           }
           for(auto it : adj[nod]){
               int to=it.first, prc=it.second;
               if(pric+prc<cost[to]){
                  cost[to]=pric+prc;
                  q.push({stp+1,{to,cost[to]}});
               }
           }
       }

       if(cost[dst]==INT_MAX){
           return -1;
       }
       return cost[dst];
    }
};