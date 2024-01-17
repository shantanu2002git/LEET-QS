class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& bac) {
        int n=bac.size();
        if(n==0 || n==1){
            return bac;
        }
        map<int,int>mp;
        for(auto it : bac){
            mp[it]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto it : mp){
            q.push({it.second,it.first});
        }

        vector<int>res;
        while(q.top().first>0){
            auto it1=q.top();
            q.pop();
            res.push_back(it1.second);
            it1.first--;

            auto it2=q.top();
            q.pop();
            if(it2.first>0){
                res.push_back(it2.second);
                it2.first--;
            }

            q.push(it1);
            q.push(it2);
        }
        return res;
    }
};