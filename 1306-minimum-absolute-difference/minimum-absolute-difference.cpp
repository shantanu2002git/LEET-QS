class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>res;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mx = 1e9;
        
        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            
            if (diff == mx) {
                res.push_back({arr[i - 1], arr[i]});
                continue;
            } else if (diff < mx) {
                mx = diff;
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return res;
    }
};
