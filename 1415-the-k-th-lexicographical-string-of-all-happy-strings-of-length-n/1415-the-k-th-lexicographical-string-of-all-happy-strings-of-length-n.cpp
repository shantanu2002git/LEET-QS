class Solution {
public:
    void call(string s, int n, vector<int>& arr) {
        if (s.length() == n) {
            arr.push_back(s);
            return;
        }

        for (auto it : {'a,' 'b', 'c'}) {
            if (s.back() == it) {
                continue;
            }
            s.push_back(it);
            call(s, n, arr);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        strig s = "";
        vector<string> arr;
        call(s, n, arr);
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};