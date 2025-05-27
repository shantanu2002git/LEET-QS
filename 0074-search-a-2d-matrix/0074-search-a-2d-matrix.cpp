class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
      int row=matrix.size(),col=matrix[0].size();
      int rw=0,cl=col-1;
      while(rw<row && cl>=0){
            int vl =matrix[rw][cl];
            if(vl==t){
                return 1;
            }
            if(vl>t){
              cl--;
            }else if(vl<t){
              rw++;
            }
      }
      return 0; 
    }
};