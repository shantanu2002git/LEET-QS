class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
       vector<int>not_lost;
       vector<int>one_lost;
       map<int,int>win,los;
       for(auto it : mat){
int wn=it[0],ls=it[1];
win[wn]++;
los[ls]++;
       }

       for(auto it : los){
           if(it.second==1){
               one_lost.push_back(it.first);
           }
       }

       for(auto it : win){
           if(los.find(it.first)==los.end()){
               not_lost.push_back(it.first);
           }
       }


       return {not_lost,one_lost};


    }
};