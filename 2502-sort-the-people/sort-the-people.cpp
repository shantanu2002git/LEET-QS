class Solution {
public:
    vector<string> sortPeople(vector<string>& na, vector<int>& h) {
        vector<pair<int, string>> vc;
        int n = na.size();
        for (int i = 0; i < n; i++) {
            vc.push_back({h[i], na[i]});
        }
        sort(vc.begin(), vc.end(), [&](pair<int,string>p1, pair<int,string>p2){
            return p1.first>p2.first;
        });
        vector<string> res;
        for (auto it : vc) {
            res.push_back(it.second);
        }
        return res;
    }
};