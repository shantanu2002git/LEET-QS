class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        set<int>rw,cl;
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if( mat[i][j]==0){
                  rw.insert(i);
                  cl.insert(j);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                if(rw.count(i) || cl.count(j)){
                    mat[i][j]=0;
                }
            }
        }
        // return mat;
    }
};