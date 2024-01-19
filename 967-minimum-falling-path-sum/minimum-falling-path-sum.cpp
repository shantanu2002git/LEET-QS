class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
      int n=mat.size();
      int ans=INT_MAX;
      for(int i=1; i<n; i++ ){
          for(int j=0; j<n; j++){
              int lef,rig,mid;
              if(j==0){
                  rig=mat[i-1][j+1];
                  mid=mat[i-1][j];
                  mat[i][j]+=min(rig,mid);
              }
              else if(j==n-1){
                  mid=mat[i-1][j];
                  lef=mat[i-1][j-1];
                  mat[i][j]+=min(mid,lef);
              }
              else {
                  lef=mat[i-1][j-1];
                  mid=mat[i-1][j];
                  rig=mat[i-1][j+1];
                  mat[i][j]+=min(lef,min(mid,rig));
              }
          }
      } 
      for(int i=0; i<n; i++){
          ans=min(ans,mat[n-1][i]);
      } 
      return ans;
    }
};