class Solution {
public:
vector<vector<int>>res;
void cal(int k, int trg, int idx , vector<int>&tem){
    if(trg<0 || k<0) return;
    if(trg==0 && k==0){
        res.push_back(tem);
        return;
    }

    for(int i=idx; i<=9; i++){
        tem.push_back(i);
        cal(k-1,trg-i,i+1,tem);
        tem.pop_back();
    }

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>tem;
        cal(k,n,1,tem);
        return res;
    }
};