class Solution {
public:
vector<vector<int>>res;
void cal(vector<int>&cdi, vector<int>&tem, int idx, int n , int trg){
    if(idx==n){
        if(trg==0){
            res.push_back(tem);
        }
        return;
    }

    if(cdi[idx]<=trg){
        tem.push_back(cdi[idx]);
        cal(cdi,tem,idx,n,trg-cdi[idx]);
        tem.pop_back();
    }
    cal(cdi,tem,idx+1,n,trg);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>tem;
        int n=candidates.size();
        cal(candidates, tem,0, n, target);
        return res;
    }
};