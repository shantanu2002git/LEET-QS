class Solution {
       private:

    int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

    bool valid_D(int x, int y, int n,int m){
  return (x>=0 && x<n && y>=0 && y<m);
}
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int fres=0;
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                 q.push({i,j});
                }else if(grid[i][j]==1){
                    fres++;
                }
            }
        }
int ans=-1;
while(!q.empty()){
    int nq=q.size();
    while(nq--){
        auto fnt=q.front();
        q.pop();
        int xi=fnt.first;
        int yi=fnt.second;
        for(int i=0; i<4; i++){
            int nx=xi+dx[i];
            int ny=yi+dy[i];
            if(valid_D(nx,ny,n,m) && grid[nx][ny]==1){
                q.push({nx,ny});
                grid[nx][ny]=2;
                fres--;
            }
        }
    }
    ans++;
}

if(fres>0) return -1;
if(ans==-1) return 0;
return ans;
    }
};