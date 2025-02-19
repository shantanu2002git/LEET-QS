class Solution {
public:
    void call(string s, int n, vector<string>& arr) {
        if (s.length() == n) {
            arr.push_back(s);
            s="";
            return;
        }

        for (char it : {'a', 'b', 'c'}) {
            if (!s.empty() && s.back() == it) { 
                continue;
            }
            s.push_back(it);
            call(s, n, arr);
            s.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string s = "";
        vector<string> arr;
        call(s, n, arr);
        sort(arr.begin(), arr.end());
        
        return (k > arr.size()) ? "" : arr[k - 1]; 
    }
};
