class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        map<char,long long>mps;
        long long n=s.size(), total=0, mx=INT_MIN;
        for(int i=0; i<n; i++){
            mps[s[i]]=mps[s[i]]+cost[i];
    mx = std::max(static_cast<long long>(mx), static_cast<long long>(mps[s[i]]));

            total=cost[i]+total;
        }
        // vector<long long>stor;
        // for(auto it : mps){
        //     cout<<it.first<<" "<<it.second<<endl;
        //     stor.push_back(it.second);
        // }
        // sort(stor.begin(), stor.end());
        // long long res=accumulate(stor.begin(), stor.end()-1,0);
        return total-mx;
    }
};