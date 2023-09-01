class Solution {
public:
    vector<int> countBits(int n) {
        int c=0;
        vector<int>vc;
        for(int i=0; i<=n; i++){
           
          c=( __builtin_popcount(i));
            vc.push_back(c);
            
            
        }
        return vc;
       
    }
};