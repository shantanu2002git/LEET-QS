class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>vis(n+1,INT_MAX); // a network of n nodes, labeled from 1 to n
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vis[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int mincost=pq.top().first;
            int topnd=pq.top().second;
        pq.pop();
        for(auto it : adj[topnd]){
            int nib=it.first;
            int niwt=it.second;

            if(mincost+niwt<vis[nib]){
                vis[nib]=mincost+niwt;
                pq.push({vis[nib],nib});
            }
        }
            
        }

        int res=0;
        for(int i=1; i<=n; i++){
            if(vis[i]==INT_MAX){
                res=-1;
                break;
            }else{
                res=max(res,vis[i]);
            }
        }
        return res;

    }
};