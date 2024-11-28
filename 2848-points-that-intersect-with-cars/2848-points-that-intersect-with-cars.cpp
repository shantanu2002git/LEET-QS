class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {

        vector<int>track(100+5);
        for(auto it : nums){
            track[it[0]]++;
            track[it[1]+1]--;
        }
        int res=0;
        for(int i=1;i<100; i++){
            track[i]+=track[i-1];
            if(track[i]>0){
                res++;
            }
        }
        return res;
    }
};