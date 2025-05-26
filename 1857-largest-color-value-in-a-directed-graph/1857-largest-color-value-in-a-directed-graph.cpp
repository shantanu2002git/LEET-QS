class Solution {
public://https://www.youtube.com/watch?v=V6LnZaX7zpk
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();/*No of colors == no of Nodes */
        vector<vector<int>>adj(n);
        vector<int>indeg(n);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            indeg[edge[1]]++;
        }

        vector<vector<int>>count(n,vector<int>(26));
        queue<int>q;

        for(int i=0; i<n; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        int ans=0,nodeseen=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            nodeseen++;/*INcrement to detect cycle*/
            count[node][colors[node]-'a']++;/*this particular node having this color*/
            ans=max(ans,count[node][colors[node]-'a']);
            
            for(auto it : adj[node]){
                for(int i=0; i<26; i++){
                    count[it][i]=max(count[it][i],count[node][i]);
                }
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
return nodeseen < n ? -1 : ans;
    }
};