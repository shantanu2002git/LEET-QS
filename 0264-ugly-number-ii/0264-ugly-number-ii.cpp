class Solution {
public:
    int nthUglyNumber(int n) {
        int large = 1691;
        vector<int> resarr;
        resarr.push_back(1);
        for (int i = 2; i <= large; i++) {
            if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
                resarr.push_back(i);
            }
        }
        for(auto it  : resarr){
            cout<<it<<" ";
        }
        return resarr[n-1];
    }
};