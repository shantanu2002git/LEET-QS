class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
         int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        vector<vector<int>> prefixSum(n , vector<int>(m, 0));

        // Calculate the prefix sum
        for (int i = 0; i <n; ++i) {
            for (int j = 0; j <m; ++j) {
                prefixSum[i][j]=grid[i][j];
                if(i>0) {
                    prefixSum[i][j]=prefixSum[i][j]+prefixSum[i-1][j];//up
                }
                if(j>0){
                    prefixSum[i][j]=prefixSum[i][j]+prefixSum[i][j-1];//dw
                }
                if(i>0 && j>0){
                    prefixSum[i][j]=prefixSum[i][j]-prefixSum[i-1][j-1];//common
                }
                if(prefixSum[i][j]<=k){
                    res++;
                }
              
            }
        }
        //  for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
                
        //         cout<<prefixSum[i][j]<<" ";
        //     }
        //      cout<<endl;
        // }
        return res;
    }
};