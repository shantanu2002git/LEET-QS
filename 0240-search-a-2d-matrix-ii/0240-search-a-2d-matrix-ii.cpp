class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mtx, int t) {
        int row=mtx.size(),col=mtx[0].size();
        int rw=0,cl=col-1;
        while(rw<row && cl>=0){
            int vl=mtx[rw][cl];
            if(vl==t){
                return 1;
            }
            if(vl>t){
                cl--;
            }else{
                rw++;
            }
        }
        return 0;
    }
};