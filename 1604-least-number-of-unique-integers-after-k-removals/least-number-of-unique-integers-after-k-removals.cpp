#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto it : arr){
            mp[it]++;
        }

        vector<pair<int,int>> vp(mp.begin(), mp.end());

        sort(vp.begin(),vp.end(),[](pair<int,int>& p1, pair<int,int>& p2){
            return p1.second < p2.second;
        });

        for(auto it : vp){
            int vl=it.first, f=it.second;
            while(k > 0 && f > 0){
                k--;
                f--;
            }
            if (f == 0) {
                mp.erase(it.first);
            }
        }
        
        return mp.size();
    }
};
