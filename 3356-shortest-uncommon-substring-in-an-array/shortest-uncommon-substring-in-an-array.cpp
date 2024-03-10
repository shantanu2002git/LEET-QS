class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
     

        unordered_map<string, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            unordered_set<string> st;
            for (int j = 0; j < arr[i].size(); j++) {
                string temp;
                for (int k = j; k < arr[i].size(); k++) {
                    temp += arr[i][k];
                    st.insert(temp);
                }
            }
            for (auto it : st)
                mp[it]++;
        }
        vector<string> ans;
        for (int i = 0; i < arr.size(); i++) {
            string res;
            for (int j = 0; j < arr[i].size(); j++) {
                string temp;
                for (int k = j; k < arr[i].size(); k++) {
                    temp += arr[i][k];
                    if (mp[temp] == 1) {
                        if (res.size() == 0)
                            res = temp;
                        else {
                            if (temp.size() < res.size())
                                res = temp;
                            else if (res.size() == temp.size())
                                res = min(res, temp);
                        }
                    }
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};