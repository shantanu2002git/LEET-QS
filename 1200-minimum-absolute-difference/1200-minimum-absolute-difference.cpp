class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mx = INT_MAX, n = arr.size();
        vector<vector<int>> res;
        for (int i = 1; i < n; i++) {
            int dif = arr[i] - arr[i - 1];
            if (dif == mx) {
                res.push_back({arr[i - 1] ,arr[i]  });
            } else if (dif < mx) {
                mx = dif;
                res.clear();
                res.push_back( {arr[i - 1], arr[i] });
            }
        }
        return res;
    }
};