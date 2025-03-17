class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<vector<string>>res;
        for(auto it : strs){
            string s=it;
            sort(it.begin(), it.end());
            mp[it].push_back(s);
        }

        for(auto it : mp){
            res.push_back(it.second);
        }
        return res;
    }
};