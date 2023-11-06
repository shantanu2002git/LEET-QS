class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<int>mn;
        int n=p.size();
        int mni=p[0],mx=-1e9;
        for(int  i=0; i<n; i++){
          mni=min(mni,p[i]);
        mx=max(mx,p[i]-mni);
        }
        return mx;
    }
};