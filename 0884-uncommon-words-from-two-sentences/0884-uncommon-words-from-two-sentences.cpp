class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> mp;
        s1 = s1 +' ';
        s2 = s2 + " ";
        string s = "";
        vector<string> res;
        for (auto i1 : s1) {

            if (i1 == ' ') {
                mp[s]++;
                s = "";
                continue;
            }
            s = s + i1;
            // mp[i1]++;
        }
        s="";
        for (auto i2 : s2) {
            if (i2 == ' ') {
                mp[s]++;
                s = "";continue;
            }
            s = s + i2;
        }
        for (auto it : mp) {
            // cout<<it.first<<" "<<it.second<<endl;
            if (it.second == 1) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};