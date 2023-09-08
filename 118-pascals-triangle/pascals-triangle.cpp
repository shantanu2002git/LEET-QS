class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>pc(n);
        for(int i=0; i<n; i++){
            pc[i].resize(i+1);
            pc[i][0]=pc[i][i]=1;
            for(int j=1; j<i; j++){
                pc[i][j]=pc[i-1][j-1]+pc[i-1][j];
            }
        }
        return pc;
    }
};