class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>frq;
        for(auto it : nums)
        {
            frq[it]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto [x1,x2] : frq)
        { 
            pq.push({x2,x1});
        }

        vector<int>res;
        
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};