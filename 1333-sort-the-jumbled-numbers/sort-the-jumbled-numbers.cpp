class Solution {
public:
    vector<int> sortJumbled(vector<int>& mpp, vector<int>& nums) {
        map<char, char> mp;
        for (int i = 0; i < mpp.size(); i++) {
            mp['0' + i] = '0' + mpp[i];
        }
        
        vector<pair<int, int>> num_pairs;
        for (int num : nums) {
            string si = to_string(num);
            string ni = "";
            for (char ch : si) {
                ni += mp[ch];
            }
            num_pairs.push_back({num, stoi(ni)});
        }

        sort(num_pairs.begin(), num_pairs.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<int> res;
        for (auto& p : num_pairs) {
            res.push_back(p.first);
        }

        return res;
    }
};
