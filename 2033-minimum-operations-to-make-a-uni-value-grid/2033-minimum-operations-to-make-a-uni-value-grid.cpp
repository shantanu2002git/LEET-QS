class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> mtxele;
        for (auto it : grid) {
            for (auto i : it) {
                mtxele.push_back(i);
            }
        }
        sort(mtxele.begin(), mtxele.end());\
        int n=mtxele.size();
        int midele=mtxele[n/2],res=0;

        for(auto j : mtxele ){
            if(abs(j-midele)%x){
                return -1;
            }
            res=res+abs(j-midele);
        }

        return (res%x==0) ? res/x : -1;

        /*
        1 2 3 5 7
         1  1 2
        
        */
    }
};