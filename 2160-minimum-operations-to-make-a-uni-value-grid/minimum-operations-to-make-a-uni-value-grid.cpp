class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
       int n=grid.size(),m=grid[0].size();
       vector<int>stor;
       for(int i=0; i<n; i++){
           for(int j=0;j<m; j++){
            stor.push_back(grid[i][j]);
           }
           }

           sort(stor.begin(),stor.end());
           int sn=stor.size();
           int md=stor[sn/2],s=0;
           for(auto it : stor){
               if(abs(it-md)%x){
                   return -1;
               }
               s=s+abs(it-md);  
           }
           return (s%x==0) ? s/x : -1;

    }

};

// 2 4 6 8
// 4 2 0 2= 8/2=4