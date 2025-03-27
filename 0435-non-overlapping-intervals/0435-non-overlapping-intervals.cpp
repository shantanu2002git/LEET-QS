bool cmp(vector<int>&a, vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intv) {
        sort(intv.begin(),intv.end(),cmp);
        int mx=-1e9,c=0;
        for(auto it : intv)
        {
int x=it[0];
int y=it[1];
if(x>=mx){
    mx=y;
}else{
    c++;
}
        }
        return c;

    }
};