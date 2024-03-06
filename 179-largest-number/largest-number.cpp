
class Solution {
public:
    string largestNumber(vector<int>& arr) {
        int n = arr.size();
        vector<string> si;
        for (int i = 0; i < n; i++) {
            si.push_back(to_string(arr[i]));
        }
        sort(si.begin(), si.end(),
             [](string a, string b) { return (a + b) > (b + a); });
        string s = "";
        for (auto it : si) {
            s += it;
        }
        // Handle the case when the result is "0"
        if (s[0] == '0') {
            return "0";
        }
        return s;
    }
};
