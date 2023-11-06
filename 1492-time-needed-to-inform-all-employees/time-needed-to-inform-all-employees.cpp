class Solution {
public:
    int numOfMinutes(int n, int hID, vector<int>& manager, vector<int>& informTime) {
      vector<int>adj[n];
      for(int i=0; i<n ;i++){
if(manager[i]!=-1){
    adj[manager[i]].push_back(i);
}
      }

int mx=-1e9;
      queue<pair<int,int>>q;
      q.push({hID,0});
      while(!q.empty()){
          auto it =q.front();
          q.pop();
          int par=it.first,tim=it.second;
          mx=max(mx,tim);
          for(auto it : adj[par]){
              q.push({it,tim+informTime[par]});
          }
      } 
      return mx; 
    }
};