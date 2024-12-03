class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prp) {
      vector<vector<int>>adj(n);
       vector<int>ind(n,0);
       for(auto it : prp){
           adj[it[1]].push_back(it[0]);
           ind[it[0]]++;
       }
       queue<int>q;
       for(int i=0; i<n;i++){
           if(ind[i]==0){
               q.push(i);
           }
       }
 vector<int>topo,empty;
       while(!q.empty()){
           int fnt=q.front();
q.pop();


topo.push_back(fnt);


for(auto nei : adj[fnt]){
    ind[nei]--;
    if(ind[nei]==0){
        q.push(nei);
    }
}
}

return (topo.size()==n) ? topo : empty ;
    }
};