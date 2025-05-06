class Solution {
    
    private:

    int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

    bool valid_D(int x, int y, int n,int m){
  return (x>=0 && x<n && y>=0 && y<m);
}
public:
   void cal(int x, int y, int n, int m,vector<vector<char>>& grid ){
queue<pair<int,int>>q;
q.push({x,y});
grid[x][y]='0';
while(!q.empty()){
    int nq=q.size();
    while(nq--){
        auto fnt=q.front();
        q.pop();
        int xi=fnt.first,yi=fnt.second;
        for(int i=0; i<4; i++){
            int nx=xi+dx[i];
            int ny=yi+dy[i];
            if(valid_D(nx,ny,n,m) && grid[nx][ny]!='0'){
                q.push({nx,ny});
                grid[nx][ny]='0';
            }

        }
    }
}
   }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int c=0;
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++ ){
                if(grid[i][j]=='1'){
                    cal(i,j,n,m,grid);
                    c++;
                }
            }
        }
        return c;
    }
};