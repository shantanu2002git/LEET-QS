class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
   
        vector<int>ele;
        for(auto it : grid){
            for(auto l : it){
                ele.push_back(l);
            }
        }
        sort(ele.begin(), ele.end());
        int n=ele.size(), tl=0;
        int md=ele[n/2];
        for(auto it : ele){
            if((md-it)%x) return -1;
                 tl+=abs(md-it)/x;
        }
        return tl;
    }
};