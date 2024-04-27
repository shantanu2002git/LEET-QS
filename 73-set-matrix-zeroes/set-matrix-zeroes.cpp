class Solution {
public:
    void setZeroes(vector<vector<int>>& mtx) {
        int n=mtx.size(),m=mtx[0].size();
        bool rw_flg1=0,cl_flg2=0;
        // O(n*n) S.C o(1)
        // 1st row
        for(int i=0; i<n; i++){
            if(mtx[i][0]==0){
                rw_flg1=true;
            }
        }
        // 1st col
        for(int j=0; j<m; j++){
            if(mtx[0][j]==0){
                cl_flg2=true;
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(mtx[i][j]==0){
                    mtx[i][0]=mtx[0][j]=0;
                }
            }
        }

for(int i=1; i<n; i++){
    for(int j=1; j<m; j++){
        if(mtx[i][0]==0 || mtx[0][j]==0){
            mtx[i][j]=0;
        }
    }
}

if(rw_flg1==true){
    for(int i=0; i<n; i++){
        mtx[i][0]=0;
    }
}

if(cl_flg2==true){
    for(int j=0; j<m;j++){
        mtx[0][j]=0;
    }
}
        /*
        vector<vector<int>> mtx1(n,vector<int>(m,-1));
int dx[4]={1,1,-1,-1};
int dy[4]={-1,-1,1,1,};
        for(int i=0;i<n;i++){
          for(int j=0;j<m; j++){
           if(mtx[i][j]==0){

          int rfrw=j,lfrw=j;
          while(rfrw<m){
           mtx1[i][rfrw++]=0;
          }
          while(lfrw>=0){
            mtx1[i][lfrw--]=0;
          }
          
          int tpcl=i,btcl=i;
          while(tpcl>=0){
           mtx1[tpcl--][j]=0;
          }
          while(btcl<n){
           mtx1[btcl++][j]=0;
           }
           } 
          }
        }

 for(int i=0; i<mtx.size(); i++){
    for(int j=0; j<mtx[0].size(); j++){
     if(mtx1[i][j]==-1){
      mtx1[i][j]=mtx[i][j];
     }
    }
  }
  mtx.clear();
  mtx=mtx1;
  */

    }
};