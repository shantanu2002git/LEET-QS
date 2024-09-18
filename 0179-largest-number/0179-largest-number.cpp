class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> si;
        for (auto it : nums) {
            si.push_back(to_string(it));
        }
        sort(si.begin(), si.end(),
             [](string a, string b) { return ((a + b) > (b + a)); });

        string res = "";
        for (auto i : si) {
            res = res + i;
        }
        if (res[0] == '0') {
            return "0";
        }
        return res;
    }
};