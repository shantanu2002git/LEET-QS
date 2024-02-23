class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>mytrust(n+1,0),othertrust(n+1,0);
        for(auto it : trust){
            mytrust[it[0]]++;
            othertrust[it[1]]++;
        }
        for(int i=1; i<=n; i++){
            if(mytrust[i]==0 && othertrust[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};